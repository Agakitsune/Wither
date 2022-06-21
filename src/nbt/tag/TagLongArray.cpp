#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagLongArray::decode(std::ifstream &stream) {
    nbt::TagLong tag;
    int32_t size = nbt::misc::decodeNumber(stream, 4);
    this->resize(size);
    for (size_t i = 0; i < size; ++i) {
        tag.decode(stream);
        this->push_back(tag);
    }
}

void nbt::TagLongArray::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, this->size(), 4);
    for (TagLong &tag : *this)
        tag.encode(stream);
}
