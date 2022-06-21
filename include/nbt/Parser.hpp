#pragma once

#include "Tag.hpp"
#include "Misc.hpp"

namespace nbt {

    namespace parser {

        void parseFile(const std::string &filepath, nbt::Tag &tag);

    } // namespace parser

} // namespace nbt
