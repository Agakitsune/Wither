#include "nbt/Operator.hpp"
#include "nbt/Misc.hpp"

void nbt::misc::encodeNumber(std::ofstream &stream, int64_t number, size_t size, nbt::misc::endianess endianess) {
    char tmp[size];

    switch (endianess) {
        case nbt::misc::BigEndian:
            for (size_t i = 0; i < size; ++i) {
                tmp[i] = (char)((number >> ((size - 1 - i) * 8)) & 0xff);
            }
            stream.write(tmp, size);
            break;
        case nbt::misc::LittleEndian:
            for (size_t i = 0; i < size; ++i)
                tmp[i] = (char)((number >> (i * 8)) & 0xff);
            stream.write(tmp, size);
            break;
        default:
            break;
    }
}

void nbt::misc::encodeString(std::ofstream &stream, const std::string &string, size_t size) {
    stream.write(string.data(), size);
}

int64_t nbt::misc::decodeNumber(std::ifstream &stream, size_t size, nbt::misc::endianess endianess) {
    char tmp[size];
    int64_t result = 0;

    switch (endianess) {
        case nbt::misc::BigEndian:
            stream.read(tmp, size);
            for (size_t i = 0; i < size; ++i) {
                result += tmp[i];
                if (i + 1 < size)
                    result <<= 8;
            }
            return result;
        case nbt::misc::LittleEndian:
            stream.read(tmp, size);
            for (size_t i = 0; i < size; ++i)
                result += (tmp[i] << (8 * i));
            return result;
        default:
            return 0;
    }
    return 0;
}

std::string nbt::misc::decodeString(std::ifstream &stream, size_t size) {
    char tmp[size + 1];

    stream.read(tmp, size);
    tmp[size] = '\0';
    return std::string(tmp);
}

std::string nbt::displayTag(nbt::Tag &tag) {
    return std::string(tag);
}

nbt::TagList::operator std::string() {
    std::string str = "[";
    auto string = []<typename T>(T &tag) -> std::string{
        return std::string(tag);
    };

    for (Tag &tag : *this) {
        str.append(std::visit(string, tag));
        str.append(", ");
    }
    if (size() > 0)
        str.erase(str.end() - 2, str.end());
    str.append("]");
    return str;
}
