#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::Tag::decode(std::ifstream &stream) {
    int8_t id;
    nbt::TagString name;
    auto decoder = [&stream]<typename T>(T &tag) {
        tag.decode(stream);
    };

    id = nbt::misc::decodeNumber(stream, 1);
    switch (id) {
        case TAG_END: *this = TagEnd(); break;
        case TAG_BYTE: *this = TagByte(); break;
        case TAG_SHORT: *this = TagShort(); break;
        case TAG_INT: *this = TagInt(); break;
        case TAG_LONG: *this = TagLong(); break;
        case TAG_FLOAT: *this = TagFloat(); break;
        case TAG_DOUBLE: *this = TagDouble(); break;
        case TAG_BYTE_ARRAY: *this = TagByteArray(); break;
        case TAG_STRING: *this = TagString(); break;
        case TAG_LIST: *this = TagList(); break;
        case TAG_COMPOUND: *this = TagCompound(); break;
        case TAG_INT_ARRAY: *this = TagIntArray(); break;
        case TAG_LONG_ARRAY: *this = TagLongArray(); break;
        default: *this = TagEnd(); break;
    }
    if (index() == 0)
        return;
    name.decode(stream);
    std::visit(decoder, *this);
    setName(name.getData());
}

void nbt::Tag::encode(std::ofstream &stream) {
    nbt::TagString name(this->getName());
    auto encoder = [&stream]<typename T>(T &tag) {
        tag.encode(stream);
    };

    nbt::misc::encodeNumber(stream, this->index(), 1);
    name.encode(stream);
    std::visit(encoder, *this);
}
