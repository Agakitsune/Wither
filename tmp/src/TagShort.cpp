#include "nbt/tag/TagShort.hpp"

nbt::TagShort::TagShort(int16_t value) {
    _data = value;
}

nbt::TagShort::TagShort(nbt::TagShort &tag) {
    _data = tag.getValue();
}

void nbt::TagShort::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagShort::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagShort::stringify(std::ofstream &stream) const {
    std::string value;

    value.append(std::to_string(_data));
    value.append("S");
    stream.write(value.data(), value.size());
}

std::string nbt::TagShort::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Short> ");
    }
    value.append(std::to_string(_data));
    value.append("S");
    return value;
}
