#pragma once

#include <cstddef>

class MyString {
public:
    MyString();
    explicit MyString(const char* c_str);
    ~MyString();

    MyString(const MyString&) = delete;
    MyString& operator=(const MyString&) = delete;

    MyString(MyString&& other) noexcept;
    MyString& operator=(MyString&& other) noexcept;

    [[nodiscard]] size_t length() const;
    [[nodiscard]] const char* c_str() const;

    void append(const MyString& other);

    void print() const;

private:
    char* data_;
    size_t length_;
};