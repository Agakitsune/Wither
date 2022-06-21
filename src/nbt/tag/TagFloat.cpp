#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

union TagFloatCoder {
    int32_t _integer;
    float _floating;
};

void nbt::TagFloat::decode(std::ifstream &stream) {
    TagFloatCoder coder;

    coder._integer = nbt::misc::decodeNumber(stream, 4);
    _data = coder._floating;
}

void nbt::TagFloat::encode(std::ofstream &stream) {
    TagFloatCoder coder;

    coder._floating = _data;
    nbt::misc::encodeNumber(stream, coder._integer, 4);
}
