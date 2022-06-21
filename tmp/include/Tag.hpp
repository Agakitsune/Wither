#pragma once

#include "abstract/ATagPtr.hpp"

#include "TagEnd.hpp"
#include "TagByte.hpp"
#include "TagShort.hpp"
#include "TagInt.hpp"
#include "TagLong.hpp"
#include "TagFloat.hpp"
#include "TagDouble.hpp"
#include "TagByteArray.hpp"
#include "TagString.hpp"
#include "TagList.hpp"
#include "TagCompound.hpp"
#include "TagIntArray.hpp"
#include "TagLongArray.hpp"

#include <variant>
#include <memory>

namespace nbt {

    using TagVariant = std::variant<
        // TagEnd,
        TagByte,
        TagShort,
        TagInt,
        TagLong,
        TagFloat,
        TagDouble,
        TagByteArray,
        TagString,
        TagList,
        TagCompound,
        TagIntArray,
        TagLongArray
    >;

    class Tag : public ATagPtr<TagVariant> {
        public:
            explicit Tag() = default;

            template<typename T>
            explicit Tag(T &tag) {
                // _data = std::unique_ptr<TagVariant>(tag.getValue());
            }

            Tag(const Tag& other) {
                auto get = []<typename T>(T &tag) -> std::unique_ptr<TagVariant> {
                    return std::make_unique<TagVariant>(tag);
                };
                _data = std::visit(get, *other._data);

                // _data = std::make_unique<TagVariant>(res);
            }

            Tag(Tag& other) {
                // _data = std::unique_ptr<TagVariant>(*other.getValue());
            }

            ~Tag() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

            Tag& operator=(Tag&& other) {
                this->_data = std::move(other._data);
                return *this;
            }

            // Tag& operator=(const Tag&& other) {
            //     this->_data = std::move(other._data);
            //     return *this;
            // }

            // Tag& operator=(const Tag& other) {
            //     this->_data = std::move(other._data);
            //     return *this;
            // }

        protected:
        private:
    };

} // namespace nbt
