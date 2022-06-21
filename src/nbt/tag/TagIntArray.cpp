#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagIntArray::decode(std::ifstream &stream) {
    nbt::TagInt tag;
    int32_t size = nbt::misc::decodeNumber(stream, 4);
    this->resize(size);
    for (size_t i = 0; i < size; ++i) {
        tag.decode(stream);
        this->push_back(tag);
    }
}

void nbt::TagIntArray::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, this->size(), 4);
    for (TagInt &tag : *this)
        tag.encode(stream);
}
