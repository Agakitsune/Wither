#ifndef TAGBYTE_HPP_
    #define TAGBYTE_HPP_

    #include "abstract/ATag.hpp"

namespace nbt {

    class TagByte : public ATag<int8_t> {
        public:
            explicit TagByte() = default;
            explicit TagByte(int8_t value);
            explicit TagByte(TagByte &tag);
            ~TagByte() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt

#endif /* !TAGBYTE_HPP_ */
