#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagLong::decode(std::ifstream &stream) {
    _data = nbt::misc::decodeNumber(stream, 8);
}

void nbt::TagLong::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, _data, 8);
}
