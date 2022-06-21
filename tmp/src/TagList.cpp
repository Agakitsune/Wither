#include "nbt/tag/TagList.hpp"

void nbt::TagList::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagList::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagList::stringify(std::ofstream &stream) const {
    std::string value;
    auto iter = [&stream]<typename T>(T &vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            vec[i].stringify(stream);
            if (i < vec.size() - 1)
                stream.write(", ", 2);
        }
    };

    value.append("[");
    stream.write(value.data(), value.size());
    std::visit(iter, *_data);
    stream.write("]", 1);
}

std::string nbt::TagList::toString(bool tagInfo) const {
    std::string value;
    auto size = []<typename T>(T &vec) -> size_t {
        return vec.size();
    };
    auto iter = [&value]<typename T>(T &vec) {
        for (size_t i = 0; i < vec.size(); ++i) {
            value.append(vec[i].toString(false));
            if (i < vec.size() - 1)
                value.append(", ");
        }
    };

    if (tagInfo) {
        value.append("<List{");
        value.append(indexToString(_data->index()));
        value.append("}");
        value.append("[");
        value.append(std::to_string(std::visit(size, *_data)));
        value.append("]");
        value.append("> ");
    }
    value.append("[");
    std::visit(iter, *_data);
    value.append("]");
    return value;
}
