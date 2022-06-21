#include "nbt/tag/TagDouble.hpp"

nbt::TagDouble::TagDouble(double value) {
    _data = value;
}

nbt::TagDouble::TagDouble(nbt::TagDouble &tag) {
    _data = tag.getValue();
}


void nbt::TagDouble::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagDouble::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagDouble::stringify(std::ofstream &stream) const {
    std::string value;

    value.append(std::to_string(_data));
    value.append("D");
    stream.write(value.data(), value.size());
}

std::string nbt::TagDouble::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Double> ");
    }
    value.append(std::to_string(_data));
    value.append("D");
    return value;
}

