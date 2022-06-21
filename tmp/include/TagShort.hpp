#pragma once

#include "abstract/ATag.hpp"

namespace nbt {

    class TagShort : public ATag<int16_t> {
        public:
            explicit TagShort() = default;
            explicit TagShort(int16_t value);
            explicit TagShort(TagShort &tag);
            ~TagShort() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt
