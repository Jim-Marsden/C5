//
// Created by james on 9/23/2022.
//

#include "../hw_insert.h"
#include "catch2/generators/catch_generators.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("insert - one element")
{
    auto value = GENERATE(1, 2, 5, 6, 62, 1234, 64, 99);
    auto array = mac::insert<int>(nullptr, 0, 0, value);
    REQUIRE(array != nullptr);
    REQUIRE(value == array[0]);
    delete []array;
}

TEST_CASE("insert - add back")
{
    auto value = GENERATE(1, 2, 5, 6, 62, 1234, 64, 99);
    auto const array_size{34};
    auto start_array = new int[array_size];

    for (int i = 0; i < array_size; ++i)
        start_array[i] = i;

    auto array = mac::insert(start_array, array_size, array_size, value);

    REQUIRE(array != nullptr);
    if (array != nullptr) {
        for (int i = 0; i < array_size; ++i)
            REQUIRE(array[i] == i);
        REQUIRE(value == array[array_size]);
        delete[]array;
    }
}

TEST_CASE("insert - random")
{
    auto value = GENERATE(1, 2, 3, 6, 9, 15, 24, 39);
    auto const array_size{50};
    auto start_array = new int[array_size];

    for (int i = 0; i < array_size; ++i)
        start_array[i] = 55;

    auto array = mac::insert(start_array, array_size, value, value);

    REQUIRE(array != nullptr);
    if (array != nullptr) {
        for (int i = 0; i < array_size + 1; ++i) {
            if (i == value) continue;
            REQUIRE(array[i] == 55);
        }
        REQUIRE(value == array[value]);
        delete[]array;
    }
}

TEST_CASE("insert - shift test")
{
    auto value = GENERATE(1, 2, 3, 6, 9, 15, 24, 39);
    auto const array_size{50};
    auto start_array = new int[array_size];

    for (int i = 0; i < array_size; ++i) {
        start_array[i] = i;
    }
    auto array = mac::insert(start_array, array_size, array_size - 1, value);

    REQUIRE(array != nullptr);
    if (array != nullptr) {

        for (int i = 0; i < array_size - 1; ++i) {
            REQUIRE(array[i] == i);
        }
        REQUIRE(array[array_size - 1] == value);
        delete[]array;
    }
}

TEST_CASE("insert - shift test from front")
{
    auto const array_size{50};
    auto start_array = new int[array_size];

    for (int i = 0; i < array_size; ++i) {
        start_array[i] = i + 1;
    }
    auto array = mac::insert<int>(start_array, array_size, 0, 0);

    REQUIRE(array != nullptr);
    if (array != nullptr) {
        for (int i = 0; i < array_size + 1; ++i) {
            REQUIRE(i == array[i]);
        }
        delete[]array;
    }
}
