#pragma once

#include "abstract/ATag.hpp"

namespace nbt {

    class TagInt : public ATag<int32_t> {
        public:
            explicit TagInt() = default;
            explicit TagInt(int32_t value);
            explicit TagInt(TagInt &tag);
            ~TagInt() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt
