#pragma once

#include "../interface/ITag.hpp"
#include "../interface/ITagValue.hpp"

#include <memory>

namespace nbt {

    template <typename T>
    class ATagPtr : public ITag, ITagValue<std::unique_ptr<T>> {
        public:
            virtual ~ATagPtr() override = default;

            virtual void setValue(std::unique_ptr<T> &value) override {
                _data = std::move(value);
            }

            virtual std::unique_ptr<T> &getValue() override {
                return _data;
            }

            virtual void setValue(T &value) {
                _data = std::make_unique<T>(value);
            }

            // virtual T &getValue() {
            //     return *_data;
            // }

            // operator T() {
            //     return getValue();
            // }

        protected:
            std::unique_ptr<T> _data;

        private:
    };

} // namespace nbt
