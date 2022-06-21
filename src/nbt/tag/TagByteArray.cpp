#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagByteArray::decode(std::ifstream &stream) {
    nbt::TagByte byte;
    int32_t size = nbt::misc::decodeNumber(stream, 4);
    this->resize(size);
    for (size_t i = 0; i < size; ++i) {
        byte.decode(stream);
        this->push_back(byte);
    }
}

void nbt::TagByteArray::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, this->size(), 4);
    for (TagByte &tag : *this)
        tag.encode(stream);
}
