#include <iostream>
#include "benchmarking.h"
#include "hw_insert.h"
#include <catch2/catch_session.hpp>
#include <fmt/format.h>
//#include <limits>

void print_t(){
    auto const array_size{50};
    auto start_array = static_cast<int *>(malloc(32 * array_size));
    if (start_array == nullptr) return;

    for (int i = 0; i < array_size; ++i) {
        start_array[i] = i + 1;
        fmt::print("{}\t", start_array[i]);
    }
    fmt::print("\n");
    auto array = insert(start_array, array_size, 0, 0);
    if (array != nullptr) {

        for (int i = 0; i < array_size + 1; ++i) {
            fmt::print("{}\t", array[i]);
        }
        fmt::print("\n");
        free(array);
    }
}
int main(int argc, char const **argv) {

    int r{};
    auto session = Catch::Session();
//    for(unsigned long long i = 0; i < 255; ++i)
    {
        benchmarking bm;
        r = session.run(argc, argv);
    }
    print_t();
    return r;
}
