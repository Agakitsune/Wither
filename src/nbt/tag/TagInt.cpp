#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagInt::decode(std::ifstream &stream) {
    _data = nbt::misc::decodeNumber(stream, 4);
}

void nbt::TagInt::encode(std::ofstream &stream) {
    nbt::misc::encodeNumber(stream, _data, 4);
}
