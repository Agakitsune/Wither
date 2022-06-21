#pragma once

#include <map>
#include <variant>
#include <string>

namespace nbt {

    class Tag;

    class TagCompound {
        public:
            TagCompound() = default;
            ~TagCompound() = default;

            std::map<int, Tag> data;
    };

    class Tag {
        public:
            Tag() = default;
            ~Tag() = default;

            std::variant<TagCompound> data;
            std::string boi;
    };

} // namespace nbt
