#pragma once

#include "ITagValue.hpp"

#include <vector>

namespace nbt {

    template <typename T>
    class ITagVector : public ITagValue<std::vector<T>> {
        public:
            virtual ~ITagVector() override = default;

            virtual void push(T &value) = 0;
            virtual void pop() = 0;

            virtual void setElement(size_t index, T &value) = 0;
            virtual T &getElement(size_t index) = 0;
            virtual void removeElement(size_t index) = 0;

    };

} // namespace nbt
