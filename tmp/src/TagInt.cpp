#include "nbt/tag/TagInt.hpp"

nbt::TagInt::TagInt(int32_t value) {
    _data = value;
}

nbt::TagInt::TagInt(nbt::TagInt &tag) {
    _data = tag.getValue();
}

void nbt::TagInt::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagInt::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagInt::stringify(std::ofstream &stream) const {
    std::string value;

    value.append(std::to_string(_data));
    stream.write(value.data(), value.size());
}

std::string nbt::TagInt::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Int> ");
    }
    value.append(std::to_string(_data));
    return value;
}
