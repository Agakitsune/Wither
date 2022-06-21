#pragma once

#include "abstract/ATag.hpp"

namespace nbt {

    class TagString : public ATag<std::string> {
        public:
            explicit TagString() = default;
            explicit TagString(const char *value);
            explicit TagString(const std::string &value);
            explicit TagString(TagString &tag);
            ~TagString() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt
