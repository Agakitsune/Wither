#include "nbt/tag/Tag.hpp"

// #include "nbt/tag/TagList.hpp"
// #include "nbt/tag/TagCompound.hpp"

void nbt::Tag::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::Tag::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::Tag::stringify(std::ofstream &stream) const {
    std::string value;
    auto string = [&stream]<typename T>(T &tag) {
        tag.stringify(stream);
    };

    std::visit(string, *_data);
}

std::string nbt::Tag::toString(bool tagInfo) const {
    std::string value;
    auto string = [&value, &tagInfo]<typename T>(T &tag) {
        value.append(tag.toString(tagInfo));
    };

    std::visit(string, *_data);
    return value;
}
