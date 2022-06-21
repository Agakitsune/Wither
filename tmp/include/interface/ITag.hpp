#ifndef ITAG_HPP_
    #define ITAG_HPP_

    #include <iostream>
    #include <fstream>

namespace nbt {

    class ITag {
        public:
            virtual ~ITag() = default;

            virtual void decode(std::ifstream &stream) = 0;
            virtual void encode(std::ofstream &stream) const = 0;
            virtual void stringify(std::ofstream &stream) const = 0;
            virtual std::string toString(bool tagInfo) const = 0;

        protected:
        private:
    };

} // namespace nbt




#endif /* !ITAG_HPP_ */
