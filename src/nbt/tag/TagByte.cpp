#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagByte::decode(std::ifstream &stream) {
    _data = nbt::misc::decodeNumber(stream, 1);
}

void nbt::TagByte::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, _data, 1);
}
