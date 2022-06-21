#pragma once

#include "Tag.hpp"

template<typename T>
requires nbt::isTag<T>
std::ostream &operator<<(std::ostream &stream, T tag) {
    stream << std::string(tag);
    return stream;
}
