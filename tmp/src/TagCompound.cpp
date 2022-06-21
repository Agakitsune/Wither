#include "nbt/tag/TagCompound.hpp"

// #include "nbt/tag/Tag.hpp"
// #include "nbt/tag/TagList.hpp"

nbt::TagCompound::TagCompound(std::map<std::string, std::unique_ptr<ITag>> &value) {
    _data = std::move(value);
}

nbt::TagCompound::TagCompound(nbt::TagCompound &tag) {
    _data = std::move(tag.getValue());
}

void nbt::TagCompound::decode(std::ifstream &stream) {
    (void)stream;
}

void nbt::TagCompound::encode(std::ofstream &stream) const {
    (void)stream;
}

void nbt::TagCompound::stringify(std::ofstream &stream) const {
    std::string value;

    value.append("{");
    stream.write(value.data(), value.size());
    for (const auto& [key, tag] : _data) {
        value.append("\t");
        value.append(key);
        value.append(": ");
        stream.write(value.data(), value.size());
        tag->stringify(stream);
        value.clear();
        value.append(",\n");
    }
    value.erase(value.end() - 1);
    stream.write(value.data(), value.size());
    stream.write("}", 1);
}

std::string nbt::TagCompound::toString(bool tagInfo) const {
    std::string value;

    if (tagInfo) {
        value.append("<Compound> ");
    }
    value.append("{\n");
    for (const auto& [key, tag] : _data) {
        value.append("\t");
        value.append(key);
        value.append(": ");
        value.append(tag->toString(false));
        value.append(",\n");
    }
    value.erase(value.end() - 2);
    value.append("}");
    return value;
}

void nbt::TagCompound::setValue(std::map<std::string, std::unique_ptr<ITag>> &value) override {
    _data = std::move(value);
}

std::map<std::string, std::unique_ptr<ITag>> &nbt::TagCompound::getValue() override {
    return _data;
}

// void nbt::TagCompound::setElement(const std::string &key, const TagVariant &tag) {
//     _data[key] = std::make_unique<nbt::Tag>(nbt::Tag(tag));
// }

void nbt::TagCompound::setElement(const std::string &key, ITag &tag) {
    // _data[key] = std::make_unique<nbt::ITag>(tag);
    _data[key] = std::unique_ptr<nbt::ITag>(new );
}

nbt::ITag &nbt::TagCompound::getElement(const std::string &key) {
    return *_data[key];
}

void nbt::TagCompound::remove(const std::string &key) {
    _data.erase(key);
}
