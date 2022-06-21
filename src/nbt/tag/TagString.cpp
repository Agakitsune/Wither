#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagString::decode(std::ifstream &stream) {
    uint16_t size = nbt::misc::decodeNumber(stream, 2);
    this->setData(nbt::misc::decodeString(stream, size));
}

void nbt::TagString::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, this->size(), 2);
    nbt::misc::encodeString(stream, getData(), this->size());
}
