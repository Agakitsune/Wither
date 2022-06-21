#include "nbt/tag/TagLongArray.hpp"

nbt::TagLongArray::TagLongArray(const std::vector<TagLong> &value) {
    _data = value;
}

nbt::TagLongArray::TagLongArray(nbt::TagLongArray &tag) {
    _data = tag.getValue();
}

void nbt::TagLongArray::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagLongArray::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagLongArray::stringify(std::ofstream &stream) const {
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

std::string nbt::TagLongArray::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Long Array");
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
