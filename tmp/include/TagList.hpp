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

#include "Misc.hpp"

#include <variant>
#include <vector>
#include <memory>
#include <functional>

namespace nbt {

    class TagList;

    using ListVariant = std::variant<
        // std::vector<TagEnd>,
        std::vector<std::unique_ptr<TagByte>>,
        std::vector<std::unique_ptr<TagShort>>,
        std::vector<std::unique_ptr<TagInt>>,
        std::vector<std::unique_ptr<TagLong>>,
        std::vector<std::unique_ptr<TagFloat>>,
        std::vector<std::unique_ptr<TagDouble>>,
        std::vector<std::unique_ptr<TagByteArray>>,
        std::vector<std::unique_ptr<TagString>>,
        std::vector<std::unique_ptr<TagList>>,
        std::vector<std::unique_ptr<TagCompound>>,
        std::vector<std::unique_ptr<TagIntArray>>,
        std::vector<std::unique_ptr<TagLongArray>>
    >;

    class TagList : public ATagPtr<ListVariant> {
        public:
            template<typename T>
            explicit TagList(std::vector<T> &value) {
                _data = std::make_unique<ListVariant>(std::unique_ptr<std::vector<T>>(new std::vector<T>(value)));
            }

            template<typename T>
            explicit TagList(std::unique_ptr<std::vector<T>> &value) {
                _data = std::move(value);
            }

            template<typename T>
            explicit TagList(TagList &tag) {
                _data = tag.getValue();
            }

            TagList(const TagList& other) {
                // _data = std::make_unique<ListVariant>(*other._data);
            }

            TagList(TagList& other) {
                // _data = std::make_unique<ListVariant>(*other._data);
            }

            ~TagList() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

            TagList(TagList&& ref) {
                _data = std::move(ref._data);
            }

            template<typename T>
            TagList(T&& ref) {
                _data = std::make_unique<ListVariant>(std::move(ref));
            }

            TagList& operator=(TagList&& other) {
                this->_data = std::move(other._data);
                return *this;
            }

        protected:
        private:
    };

} // namespace nbt
