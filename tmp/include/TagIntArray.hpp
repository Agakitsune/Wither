#pragma once

#include "abstract/ATagVector.hpp"
#include "TagInt.hpp"

#include <vector>

namespace nbt {

    class TagIntArray : public ATagVector<TagInt> {
        public:
            explicit TagIntArray() = default;
            explicit TagIntArray(std::vector<TagInt> &value);
            explicit TagIntArray(TagIntArray &tag);
            ~TagIntArray() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt
