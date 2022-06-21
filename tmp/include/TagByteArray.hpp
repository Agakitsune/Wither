#pragma once

#include "abstract/ATagVector.hpp"
#include "TagByte.hpp"

#include <vector>

namespace nbt {

    class TagByteArray : public ATagVector<TagByte> {
        public:
            explicit TagByteArray() = default;
            explicit TagByteArray(std::vector<TagByte> &value);
            explicit TagByteArray(TagByteArray &tag);
            ~TagByteArray() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt
