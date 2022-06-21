#pragma once

#include "../interface/ITag.hpp"
#include "../interface/ITagVector.hpp"

#include <string>
#include <vector>

namespace nbt {

    template<typename T>
    class ATagVector : public ITag, ITagVector<T> {
        public:
            virtual ~ATagVector() override = default;

            virtual void decode(std::ifstream &stream) override {
                (void)stream;
            }

            virtual void encode(std::ofstream &stream) const override {
                (void)stream;
            }

            virtual void stringify(std::ofstream &stream) const override {
                (void)stream;
            }

            virtual std::string toString(bool tagInfo) const override {
                return "";
            }

            virtual void setValue(std::vector<T> &data) override {
                _data = data;
            }

            virtual std::vector<T> &getValue() override {
                return _data;
            }

            virtual void push(T &value) {
                _data.push_back(value);
            }

            virtual void pop() {
                _data.pop_back();
            }

            virtual void setElement(size_t index, T &value) {
                _data[index] = value;
            }

            virtual T &getElement(size_t index) {
                return _data.at(index);
            }

            virtual void removeElement(size_t index) {
                _data.erase(_data.begin() + index);
            }

        protected:
            std::vector<T> _data;

        private:
    };

} // namespace nbt
