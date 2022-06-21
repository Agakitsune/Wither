#include "nbt/tag/TagLong.hpp"

nbt::TagLong::TagLong(int64_t value) {
    _data = value;
}

nbt::TagLong::TagLong(nbt::TagLong &tag) {
    _data = tag.getValue();
}

void nbt::TagLong::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagLong::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagLong::stringify(std::ofstream &stream) const {
    std::string value;

    value.append(std::to_string(_data));
    value.append("L");
    stream.write(value.data(), value.size());
}

std::string nbt::TagLong::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Long> ");
    }
    value.append(std::to_string(_data));
    value.append("L");
    return value;
}
