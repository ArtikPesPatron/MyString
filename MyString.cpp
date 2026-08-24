#include <iostream>
#include <cstring>

#include "MyString.hpp"

MyString::MyString()
    : data_(new char[1])
    , length_(0)
{
    data_[0] = '\0';
}

MyString::MyString(const char* c_str) : length_(0)
{
    const size_t len = std::strlen(c_str);
    data_ = new char[len + 1];
    std::strcpy(data_, c_str);
}

MyString::~MyString()
{
    delete[] data_;
}

void MyString::append(const MyString& other)
{
    const auto new_data = new char[length_ + other.length_ + 1];
    std::strcpy(new_data, data_);
    std::strcat(new_data, other.data_);
    delete[] data_;
    data_ = new_data;
    length_ += other.length_;
}

void MyString::print() const {
    std::cout << data_ << std::endl;
}

size_t MyString::length() const {
    return length_;
}

const char *MyString::c_str() const {
    return data_;
}
