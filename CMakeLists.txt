cmake_minimum_required(VERSION 3.20)
project(MyString LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyString
        main.cpp
        MyString.cpp
        MyString.hpp
)

target_compile_options(MyString PRIVATE -Wall -Wextra -Wpedantic)

add_executable(Test_MyString
    tests/MyString_tests.cpp
    MyString.cpp
)

target_include_directories(Test_MyString PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(Test_MyString PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_test(NAME MyString_Tests COMMAND Test_MyString)