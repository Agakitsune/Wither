#pragma once

#include "interface/ITag.hpp"
#include "interface/ITagValue.hpp"

#include <map>
#include <memory>

namespace nbt {

    class TagCompound : public ITag, ITagValue<std::map<std::string, std::unique_ptr<ITag>>> {
        public:
            explicit TagCompound() = default;
            explicit TagCompound(std::map<std::string, std::unique_ptr<ITag>> &data);
            explicit TagCompound(TagCompound &tag);
            ~TagCompound() override = default;

            void decode(std::ifstream &stream) override;
            void encode(std::ofstream &stream) const override;
            void stringify(std::ofstream &stream) const override;
            std::string toString(bool tagInfo) const override;

            void setValue(std::map<std::string, std::unique_ptr<ITag>> &value) override;
            std::map<std::string, std::unique_ptr<ITag>> &getValue() override;

            // void setElement(const std::string &key, const TagVariant &tag);
            template<typename T>
            void setElement(const std::string &key, T &tag) {
                // _data[key] = std::make_unique<nbt::ITag>(tag);
                _data[key] = std::unique_ptr<nbt::ITag>(new T(tag));
            }

            ITag &getElement(const std::string &key);
            void remove(const std::string &key);

        protected:
            std::map<std::string, std::unique_ptr<ITag>> _data;

        private:
    };

} // namespace nbt
