//
// Created by eitan on 03/03/2022.
//

#include "doctest.h"
#include "mat.hpp"
#include "iostream"

using namespace ariel;

string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE ("even number supplied for columns or rows - bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(5, 10, '$', '%'));
    CHECK_THROWS(mat(4, 10, '$', '%'));
}

TEST_CASE ("same symbol supplied as parameter") {
    CHECK_THROWS(mat(5, 7, '$', '$'));
}

TEST_CASE ("negative number supplied for columns or rows") {
    CHECK_THROWS(mat(-5, 7, '$', '-'));
    CHECK_THROWS(mat(5, -7, '$', '-'));
}

TEST_CASE ("Good input one row and greater than 1 columns") {
            CHECK(mat(5, 1, '@', '-') == "@@@@@");
}

TEST_CASE ("Good input one column and greater than 1 rows") {
            CHECK(mat(1, 5, '@', '-') == "@\n@\n@\n@\n@");
}

TEST_CASE ("one row and one column") {
            CHECK(mat(1, 1, '@', '-') == nospaces("@"));
}

TEST_CASE ("given character is \\n") {
    CHECK_THROWS(mat(5, 7, '\n', '-'));
    CHECK_THROWS(mat(5, 7, '-', '\n'));
}

TEST_CASE ("given character is \\t") {
    CHECK_THROWS(mat(5, 7, '\t', '-'));
    CHECK_THROWS(mat(5, 7, '-', '\t'));
}

TEST_CASE ("given character is \\r") {
    CHECK_THROWS(mat(5, 7, '\r', '-'));
    CHECK_THROWS(mat(5, 7, '-', '\r'));
}

TEST_CASE ("given character is space") {
    CHECK_THROWS(mat(5, 7, ' ', '-'));
    CHECK_THROWS(mat(5, 7, '-', ' '));
}

TEST_CASE ("given character is \\0") {
    CHECK_THROWS(mat(5, 7, '\0', '-'));
    CHECK_THROWS(mat(5, 7, '-', '\0'));
}

TEST_CASE ("Good input") {
            CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                            "@-------@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-@---@-@\n"
                                                            "@-@@@@@-@\n"
                                                            "@-------@\n"
                                                            "@@@@@@@@@"));
}