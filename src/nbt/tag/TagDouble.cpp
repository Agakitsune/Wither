#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

union TagDoubleCoder {
    int64_t _integer;
    double _floating;
};

void nbt::TagDouble::decode(std::ifstream &stream) {
    TagDoubleCoder coder;

    coder._integer = nbt::misc::decodeNumber(stream, 8);
    _data = coder._floating;
}

void nbt::TagDouble::encode(std::ofstream &stream) {
    TagDoubleCoder coder;

    coder._floating = _data;
    nbt::misc::encodeNumber(stream, coder._integer, 8);
}
