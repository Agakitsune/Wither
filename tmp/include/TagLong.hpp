#pragma once

#include "abstract/ATag.hpp"

namespace nbt {

    class TagLong : public ATag<int64_t> {
        public:
            explicit TagLong() = default;
            explicit TagLong(int64_t value);
            explicit TagLong(TagLong &tag);
            ~TagLong() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt
