#pragma once

#include "abstract/ATagVector.hpp"
#include "TagLong.hpp"

#include <vector>

namespace nbt {

    class TagLongArray : public ATagVector<TagLong> {
        public:
            explicit TagLongArray() = default;
            explicit TagLongArray(const std::vector<TagLong> &value);
            explicit TagLongArray(TagLongArray &tag);
            ~TagLongArray() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt
