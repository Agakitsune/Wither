#pragma once

#include <vector>
#include <map>
#include <string>
#include <variant>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include <boost/container/map.hpp>

namespace nbt {

    enum TagType {
        TAG_END,
        TAG_BYTE,
        TAG_SHORT,
        TAG_INT,
        TAG_LONG,
        TAG_FLOAT,
        TAG_DOUBLE,
        TAG_BYTE_ARRAY,
        TAG_STRING,
        TAG_LIST,
        TAG_COMPOUND,
        TAG_INT_ARRAY,
        TAG_LONG_ARRAY
    };

    class Tag;
    class TagList;

    class TagEnd {
        public:
            TagEnd() = default;
            ~TagEnd() = default;

            // template<typename T>
            // operator T() {
            //     return T();
            // }

            operator std::string() { return ""; }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);
    };
    class TagByte {
        public:
            TagByte() = default;
            TagByte(int8_t value) : _data(value) {}
            ~TagByte() = default;

            // template<typename T>
            // operator T() {
            //     if constexpr (std::convertible_to<int8_t, T>) {
            //         return static_cast<T>(_data);
            //     } else {
            //         throw std::runtime_error("Unable to cast TagByte");
            //     }
            // }

            operator std::string() {
                return std::to_string(_data) + "B";
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

        private:
            std::int8_t _data;
    };

    class TagShort {
        public:
            TagShort() = default;
            TagShort(int16_t value) : _data(value) {}
            ~TagShort() = default;

            operator std::string() {
                return std::to_string(_data) + "S";
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

        private:
            std::int16_t _data;
    };

    class TagInt {
        public:
            TagInt() = default;
            TagInt(int32_t value) : _data(value) {}
            ~TagInt() = default;

            operator std::string() {
                return std::to_string(_data);
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

        private:
            std::int32_t _data;
    };

    class TagLong {
        public:
            TagLong() = default;
            TagLong(int64_t value) : _data(value) {}
            ~TagLong() = default;

            operator std::string() {
                return std::to_string(_data) + "L";
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

        private:
            std::int64_t _data;
    };

    class TagFloat {
        public:
            TagFloat() = default;
            TagFloat(float value) : _data(value) {}
            ~TagFloat() = default;

            operator std::string() {
                return std::to_string(_data) + "F";
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

        private:
            float _data;
    };

    class TagDouble {
        public:
            TagDouble() = default;
            TagDouble(double value) : _data(value) {}
            ~TagDouble() = default;

            operator std::string() {
                return std::to_string(_data) + "D";
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

        private:
            double _data;
    };

    class TagByteArray : public std::vector<TagByte> {
        using vector::vector;

        public:
            operator std::string() {
                std::string str = "[";
                for (TagByte &tag : *this) {
                    str.append(std::string(tag));
                    str.append(", ");
                }
                str.erase(str.end() - 2, str.end());
                str.append("]");
                return str;
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);
    };

    class TagIntArray : public std::vector<TagInt> {
        using vector::vector;

        public:
            operator std::string() {
                std::string str = "[";
                for (TagInt &tag : *this) {
                    str.append(std::string(tag));
                    str.append(", ");
                }
                str.erase(str.end() - 2, str.end());
                str.append("]");
                return str;
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);
    };

    class TagLongArray : public std::vector<TagLong> {
        using vector::vector;

        public:
            operator std::string() {
                std::string str = "[";
                for (TagLong &tag : *this) {
                    str.append(std::string(tag));
                    str.append(", ");
                }
                str.erase(str.end() - 2, str.end());
                str.append("]");
                return str;
            }

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);
    };

    class TagString {
        public:
            TagString() = default;
            TagString(const std::string &str) : _data(str) {}
            ~TagString() = default;

            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

            size_t size() {
                return _data.size();
            }

            std::string getData() {
                return _data;
            }

            void setData(const std::string &data) {
                _data = data;
            }

            operator std::string() {
                return "'" + _data + "'";
            }

        private:
            std::string _data;
    };

    std::string displayTag(Tag &tag);

    class TagCompound : public std::vector<Tag> {
        using vector::vector;

        public:
            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

            operator std::string();
            nbt::Tag &operator[](const std::string &key);
    };

    template<typename T>
    concept isTagIntegral = std::same_as<T, TagByte> ||
        std::same_as<T, TagShort> ||
        std::same_as<T, TagInt> ||
        std::same_as<T, TagLong>;

    template<typename T>
    concept isTagFloating = std::same_as<T, TagFloat> ||
        std::same_as<T, TagDouble>;

    template<typename T>
    concept isTagNumber = isTagIntegral<T> || isTagFloating<T>;

    template<typename T>
    concept isTagArray = std::same_as<T, TagByteArray> ||
        std::same_as<T, TagIntArray> ||
        std::same_as<T, TagLongArray>;

    template<typename T>
    concept isTag = isTagNumber<T> ||
        isTagArray<T> ||
        std::same_as<T, TagEnd> ||
        std::same_as<T, TagString> ||
        std::same_as<T, TagList> ||
        std::same_as<T, TagCompound> ||
        std::same_as<T, Tag>;

    class TagList : public std::vector<Tag> {
        using vector::vector;

        public:
            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

            template<typename T>
            requires isTag<T>
            void push_back(T &tag) {
                if (this->size() == 0) {
                    this->insert(this->end(), nbt::Tag(tag));
                } else {
                    auto canPush = [&tag]<typename U>(U &elem) -> bool {
                        return std::same_as<T, U> || std::convertible_to<T, U>;
                    };
                    if (std::visit(canPush, this->at(0))) {
                        this->insert(this->end(), nbt::Tag(tag));
                    } else {
                        throw std::runtime_error("Failed to push");
                    }
                }
            }

            operator std::string();
    };

    class Tag : public std::variant<
        TagEnd,
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
    > {
        using variant::variant;

        public:
            void decode(std::ifstream &stream);
            void encode(std::ofstream &stream);

            std::string getName() { return _name; }
            void setName(const std::string &name) { _name = name; }

            template<typename T>
            operator T() {
                try {
                    return std::get<T>(*this);
                } catch (const std::bad_variant_access &e) {
                    T value;
                    auto convert = [&value]<typename U>(U &variant) {
                        if constexpr (std::convertible_to<U, T>)
                            value = static_cast<T>(variant);
                        else
                            throw std::runtime_error("Unable to cast");
                    };
                    std::visit(convert, *this);
                    return value;
                }
            }

            operator std::string() {
                std::string str;
                auto convert = [&]<typename T>(T &variant) -> std::string {
                    return std::string(variant);
                };

                return _name + ": " + std::visit(convert, *this);
            }

        private:
            std::string _name;
    };

} // namespace nbt
