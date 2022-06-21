#include "nbt/tag/TagByteArray.hpp"

nbt::TagByteArray::TagByteArray(std::vector<TagByte> &value) : _data(value) {}

nbt::TagByteArray::TagByteArray(nbt::TagByteArray &tag) : _data(tag.getValue()) {}

void nbt::TagByteArray::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagByteArray::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagByteArray::stringify(std::ofstream &stream) const {
    std::string value;

    value.append("[");
    stream.write(value.data(), value.size());
    for (size_t i = 0; i < _data.size(); ++i) {
        _data[i].stringify(stream);
        if (i < _data.size() - 1)
            stream.write(", ", 2);
    }
    stream.write("]", 1);
}

std::string nbt::TagByteArray::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Byte Array");
        value.append("[");
        value.append(std::to_string(_data.size()));
        value.append("]");
        value.append("> ");
    }
    value.append("[");
    for (size_t i = 0; i < _data.size(); ++i) {
        value.append(_data[i].toString(false));
        if (i < _data.size() - 1)
            value.append(", ");
    }
    value.append("]");
    return value;
}
