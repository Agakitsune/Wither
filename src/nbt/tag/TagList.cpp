#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagList::decode(std::ifstream &stream) {
    nbt::Tag tag;
    int8_t id = nbt::misc::decodeNumber(stream, 1);
    int32_t size = nbt::misc::decodeNumber(stream, 4);
    auto decoder = [&stream]<typename T>(T &tag) {
        tag.decode(stream);
    };

    switch (id) {
        case TAG_END: tag = TagEnd(); break;
        case TAG_BYTE: tag = TagByte(); break;
        case TAG_SHORT: tag = TagShort(); break;
        case TAG_INT: tag = TagInt(); break;
        case TAG_LONG: tag = TagLong(); break;
        case TAG_FLOAT: tag = TagFloat(); break;
        case TAG_DOUBLE: tag = TagDouble(); break;
        case TAG_BYTE_ARRAY: tag = TagByteArray(); break;
        case TAG_STRING: tag = TagString(); break;
        case TAG_LIST: tag = TagList(); break;
        case TAG_COMPOUND: tag = TagCompound(); break;
        case TAG_INT_ARRAY: tag = TagIntArray(); break;
        case TAG_LONG_ARRAY: tag = TagLongArray(); break;
        default: tag = TagEnd(); break;
    }
    for (size_t i = 0; i < size; ++i) {
        std::visit(decoder, tag);
        this->push_back(tag);
    }
}

void nbt::TagList::encode(std::ofstream &stream) {
    size_t size = this->size();
    int8_t id = 0;
    auto encoder = [&stream]<typename T>(T &tag) {
        tag.encode(stream);
    };

    if (size == 0) {
        nbt::misc::encodeNumber(stream, 0, 1);
        nbt::misc::encodeNumber(stream, 0, 4);
    } else {
        id = this->at(0).index();
        nbt::misc::encodeNumber(stream, id, 1);
        nbt::misc::encodeNumber(stream, size, 4);
        for (Tag &tag : *this)
            std::visit(encoder, tag);
    }
}
