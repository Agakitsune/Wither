#include "nbt/Parser.hpp"

void nbt::parser::parseFile(const std::string &filepath, nbt::Tag &tag) {
    std::ifstream file;

    file.open(filepath, std::ios::in | std::ios::binary);
    tag.decode(file);
    file.close();
}
