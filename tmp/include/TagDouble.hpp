#ifndef TAGDOUBLE_HPP_
    #define TAGDOUBLE_HPP_

    #include "abstract/ATag.hpp"

namespace nbt {

    class TagDouble : public ATag<double> {
        public:
            explicit TagDouble() = default;
            explicit TagDouble(double value);
            explicit TagDouble(TagDouble &tag);
            ~TagDouble() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt

#endif /* !TAGDOUBLE_HPP_ */
