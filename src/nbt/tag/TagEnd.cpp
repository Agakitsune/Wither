#include "nbt/Tag.hpp"
#include "nbt/Misc.hpp"

void nbt::TagEnd::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagEnd::encode(std::ofstream &stream) {
    // nbt::misc::encodeNumber(stream, nbt::TAG_END, 1);
}
