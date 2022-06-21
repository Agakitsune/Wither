#ifndef TAGFLOAT_HPP_
    #define TAGFLOAT_HPP_

    #include "abstract/ATag.hpp"

namespace nbt {
    class TagFloat : public ATag<float> {
        public:
            explicit TagFloat() = default;
            explicit TagFloat(float value);
            explicit TagFloat(TagFloat &tag);
            ~TagFloat() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

        protected:
        private:
    };

} // namespace nbt

#endif /* !TAGFLOAT_HPP_ */
