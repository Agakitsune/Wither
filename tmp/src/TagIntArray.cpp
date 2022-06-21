#include "nbt/tag/TagIntArray.hpp"

nbt::TagIntArray::TagIntArray(std::vector<TagInt> &value) {
    _data = value;
}

nbt::TagIntArray::TagIntArray(nbt::TagIntArray &tag) {
    _data = tag.getValue();
}

void nbt::TagIntArray::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagIntArray::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagIntArray::stringify(std::ofstream &stream) const {
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

std::string nbt::TagIntArray::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Int Array");
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
