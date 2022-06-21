#include "nbt/tag/TagByte.hpp"

nbt::TagByte::TagByte(int8_t value) {
    _data = value;
}

nbt::TagByte::TagByte(nbt::TagByte &tag) {
    _data = tag.getValue();
}

void nbt::TagByte::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagByte::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagByte::stringify(std::ofstream &stream) const {
    std::string value;

    value.append(std::to_string(_data));
    value.append("B");
    stream.write(value.data(), value.size());
}

std::string nbt::TagByte::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Byte> ");
    }
    value.append(std::to_string(_data));
    value.append("B");
    return value;
}
