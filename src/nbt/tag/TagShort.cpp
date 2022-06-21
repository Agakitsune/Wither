#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagShort::decode(std::ifstream &stream) {
    _data = nbt::misc::decodeNumber(stream, 2);
}

void nbt::TagShort::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, _data, 2);
}
