#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void setTagID(std::ifstream &stream, nbt::Tag &tag) {
    int8_t id = nbt::misc::decodeNumber(stream, 1);

    switch (id) {
        case nbt::TAG_END: tag = nbt::TagEnd(); break;
        case nbt::TAG_BYTE: tag = nbt::TagByte(); break;
        case nbt::TAG_SHORT: tag = nbt::TagShort(); break;
        case nbt::TAG_INT: tag = nbt::TagInt(); break;
        case nbt::TAG_LONG: tag = nbt::TagLong(); break;
        case nbt::TAG_FLOAT: tag = nbt::TagFloat(); break;
        case nbt::TAG_DOUBLE: tag = nbt::TagDouble(); break;
        case nbt::TAG_BYTE_ARRAY: tag = nbt::TagByteArray(); break;
        case nbt::TAG_STRING: tag = nbt::TagString(); break;
        case nbt::TAG_LIST: tag = nbt::TagList(); break;
        case nbt::TAG_COMPOUND: tag = nbt::TagCompound(); break;
        case nbt::TAG_INT_ARRAY: tag = nbt::TagIntArray(); break;
        case nbt::TAG_LONG_ARRAY: tag = nbt::TagLongArray(); break;
        default: tag = nbt::TagEnd(); break;
    }
}

void nbt::TagCompound::decode(std::ifstream &stream) {
    nbt::Tag tag;

    while (true) {
        tag.decode(stream);
        // std::cout << "ID: " << tag.index() << std::endl;
        // std::cout << "Name: " << tag.getName() << std::endl;
        if (tag.index() == 0)
            break;
        this->push_back(tag);
    }
}

void nbt::TagCompound::encode(std::ofstream &stream) {
    nbt::TagString name;

    for (Tag &tag : *this)
        tag.encode(stream);
    nbt::misc::encodeNumber(stream, TAG_END, 1);
}

nbt::TagCompound::operator std::string() {
    static size_t indent = 0;
    std::string str = "{\n";
    ++indent;
    for (Tag &tag : *this) {
        for (size_t i = 0; i < indent; ++i) { str.append("\t"); }
        str.append(std::string(tag));
        str.append(",\n");
    }
    --indent;
    str.erase(str.end() - 2);
    for (size_t i = 0; i < indent; ++i) { str.append("\t"); }
    str.append("}");
    return str;
}

nbt::Tag &nbt::TagCompound::operator[](const std::string &key) {
    for (Tag &tag : *this) {
        if (tag.getName() == key)
            return tag;
    }
    throw std::out_of_range(key + " is not in Compound");
}
