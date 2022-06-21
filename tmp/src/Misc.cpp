#include "nbt/tag/Misc.hpp"

std::string nbt::indexToString(int index) {
    switch (index) {
    case nbt::TAGEnd:
        return "End";
    case nbt::TAGByte:
        return "Byte";
    case nbt::TAGShort:
        return "Short";
    case nbt::TAGInt:
        return "Int";
    case nbt::TAGLong:
        return "Long";
    case nbt::TAGFloat:
        return "Float";
    case nbt::TAGDouble:
        return "Double";
    case nbt::TAGByteArray:
        return "Byte Array";
    case nbt::TAGString:
        return "String";
    case nbt::TAGList:
        return "List";
    case nbt::TAGCompound:
        return "Compound";
    case nbt::TAGIntArray:
        return "Int Array";
    case nbt::TAGLongArray:
        return "Long Array";
    default:
        return "Unknown";
    }
}
