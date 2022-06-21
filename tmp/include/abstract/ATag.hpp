#pragma once

#include "../interface/ITag.hpp"
#include "../interface/ITagValue.hpp"

#include <string>

namespace nbt {

    template<typename T>
    class ATag : public ITag, ITagValue<T> {
        public:
            virtual ~ATag() override = default;

            virtual void setValue(T &value) override {
                _data = value;
            }

            virtual T &getValue() override {
                return _data;
            }

            operator T() {
                return getValue();
            }

        protected:
            T _data;

        private:
    };

} // namespace nbt

template<typename T>
std::ostream &operator<<(std::ostream &stream, nbt::ATag<T> &tag) {
    return stream << tag.getValue();
}
