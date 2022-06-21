#pragma once

    #include <string>

#include "TagEnd.hpp"
#include "TagByte.hpp"
#include "TagShort.hpp"
#include "TagInt.hpp"
#include "TagLong.hpp"
#include "TagFloat.hpp"
#include "TagDouble.hpp"
#include "TagByteArray.hpp"
#include "TagString.hpp"
#include "TagList.hpp"
// #include "TagCompound.hpp"
#include "TagIntArray.hpp"
#include "TagLongArray.hpp"

namespace nbt {

    enum TagType {
        TAGEnd,
        TAGByte,
        TAGShort,
        TAGInt,
        TAGLong,
        TAGFloat,
        TAGDouble,
        TAGByteArray,
        TAGString,
        TAGList,
        TAGCompound,
        TAGIntArray,
        TAGLongArray
    };

    std::string indexToString(int index);

} // namespace nbt
