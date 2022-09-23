//
// Created by snizzfox on 9/21/22.
//

#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
#include <climits>
#include "hw_insert.h"
#include "catch2/generators/catch_generators.hpp"

/**
 * @name: int *insert(int *array, int length, int index, int value);
 * @param The array of ints into which a new value should be inserted.
 * @param length The number of elements in the array.
 * @param index The location where the value should be inserted into the array.
 * @param value The value that should be inserted into the array.
 * @return A new array of ints containing the contents of the original array plus the new value
inserted at the given index. NULL will be returned should something goes wrong.
 */
int* insert(int* array, int length, int index, int value)
{
	static constexpr auto int_bit_size{CHAR_BIT*sizeof(array[0])};

	// Check if length is 0.
	if (length==0) {
		// The array we will be manipulating
		auto new_array = static_cast<int*>(malloc(length*int_bit_size));

		// check if the new array is not valid memory.
		if (new_array==nullptr) {
			// return nullptr
			return nullptr;
		}

		// assign value to the first element
		new_array[0] = value;

		// return the new array
		return new_array;
	}

	// check if array is nullptr
	if (array==nullptr) {
		return nullptr;
	}
	// return nullptr

	// create a pointer for an int array
	int* new_array{nullptr};

	// reallocate the array and assign into the new array pointer
	new_array = static_cast<int*>(realloc(array, length*int_bit_size));

	// check to see if index is the same size as length
	if (index==length) {
		// add value to the end of the new array
		new_array[index] = value;
		// return the new array
		return new_array;
	}

	auto tail = array[length];
	// loop from index + 2 to end (2 because 1 for the actual index, and 1 so we can backtrack)
	for (int i = length+1; i>index; --i) {
		new_array[i] = new_array[i-1];
	}

	new_array[index] = value;
	return new_array;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "clion-misra-cpp2008-7-3-4"

TEST_CASE("insert - one element")
{
	auto value = GENERATE(1, 2, 5, 6, 62, 1234, 64, 99);
	auto array = insert(nullptr, 0, 0, value);
	REQUIRE(array!=nullptr);
	REQUIRE(value==array[0]);
	free(array);
}

TEST_CASE("insert - add back")
{
	auto value = GENERATE(1, 2, 5, 6, 62, 1234, 64, 99);
	auto const array_size{34};
	auto start_array = static_cast<int*>(malloc(32*array_size));
	if (start_array==nullptr) FAIL("start_array is null :c");

	for (int i = 0; i<array_size; ++i)
		start_array[i] = i;

	auto array = insert(start_array, array_size, array_size, value);

	REQUIRE(array!=nullptr);
	if (array!=nullptr) {
		for (int i = 0; i<array_size; ++i)
			REQUIRE(array[i]==i);
		REQUIRE(value==array[array_size]);
		free(array);
	}
}

TEST_CASE("insert - random")
{
	auto value = GENERATE(1, 2, 3, 6, 9, 15, 24, 39);
	auto const array_size{50};
	auto start_array = static_cast<int*>(malloc(32*array_size));
	if (start_array==nullptr) FAIL("start_array is null :c");

	for (int i = 0; i<array_size; ++i)
		start_array[i] = 55;

	auto array = insert(start_array, array_size, value, value);

	REQUIRE(array!=nullptr);
	if (array!=nullptr) {
		for (int i = 0; i<array_size+1; ++i) {
			if (i==value) continue;
			REQUIRE(array[i]==55);
		}
		REQUIRE(value==array[value]);
		free(array);
	}
}

TEST_CASE("insert - shift test")
{
	auto value = GENERATE(1, 2, 3, 6, 9, 15, 24, 39);
	auto const array_size{50};
	auto start_array = static_cast<int*>(malloc(32*array_size));
	if (start_array==nullptr) FAIL("start_array is null :c");

	for (int i = 0; i<array_size; ++i) {
		start_array[i] = i;
	}
	auto array = insert(start_array, array_size, array_size-1, value);

	REQUIRE(array!=nullptr);
	if (array!=nullptr) {

		for (int i = 0; i<array_size-1; ++i) {
			REQUIRE(array[i]==i);
		}
		REQUIRE(array[array_size-1]==value);
		free(array);
	}
}

TEST_CASE("insert - shift test from front")
{
	auto const array_size{50};
	auto start_array = static_cast<int*>(malloc(32*array_size));
	if (start_array==nullptr) return;

	for (int i = 0; i<array_size; ++i) {
		start_array[i] = i+1;
	}
	auto array = insert(start_array, array_size, 0, 0);

	REQUIRE(array!=nullptr);
	if (array!=nullptr) {

		for (int i = 0; i<array_size+1; ++i) {
			REQUIRE(i==array[i]);
		}


		//        for (int i = 0; i < array_size + 1; ++i) {
//            REQUIRE(array[i] == i);
//        }
		free(array);
	}
}

#pragma clang diagnostic pop
