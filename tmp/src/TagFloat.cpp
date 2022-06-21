#include "nbt/tag/TagFloat.hpp"

nbt::TagFloat::TagFloat(float value) {
    _data = value;
}

nbt::TagFloat::TagFloat(nbt::TagFloat &tag) {
    _data = tag.getValue();
}

void nbt::TagFloat::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagFloat::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagFloat::stringify(std::ofstream &stream) const {
    std::string value;

    value.append(std::to_string(_data));
    value.append("F");
    stream.write(value.data(), value.size());
}

std::string nbt::TagFloat::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Float> ");
    }
    value.append(std::to_string(_data));
    value.append("F");
    return value;
}
