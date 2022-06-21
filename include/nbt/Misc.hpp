#pragma once

#include "Operator.hpp"

namespace nbt {

    namespace misc {

        enum endianess {
            LittleEndian,
            BigEndian
        };

        void encodeNumber(std::ofstream &stream, int64_t number, size_t size, endianess endianess = BigEndian);
        void encodeString(std::ofstream &stream, const std::string &string, size_t size);

        int64_t decodeNumber(std::ifstream &stream, size_t size, endianess endianess = BigEndian);
        std::string decodeString(std::ifstream &stream, size_t size);

    } // namespace misc

} // namespace nbt
