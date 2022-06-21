#pragma once

namespace nbt {

    template <typename T>
    class ITagValue {
        public:
            virtual ~ITagValue() = default;

            virtual void setValue(T &data) = 0;
            virtual T &getValue() = 0;

    };


} // namespace nbt
