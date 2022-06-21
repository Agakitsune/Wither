#include "nbt/tag/TagString.hpp"

nbt::TagString::TagString(const char *value) {
    _data = value;
}

nbt::TagString::TagString(const std::string &value) {
    _data = value;
}

nbt::TagString::TagString(nbt::TagString &tag) {
    _data = tag.getValue();
}

void nbt::TagString::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagString::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagString::stringify(std::ofstream &stream) const {
    std::string value;

    value.append("'");
    value.append(_data);
    value.append("'");
    stream.write(value.data(), value.size());
}

std::string nbt::TagString::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<String> ");
    }
    value.append("'");
    value.append(_data);
    value.append("'");
    return value;
}
