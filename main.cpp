#include "benchmarking.h"
#include "hw_insert.h"
#include <catch2/catch_session.hpp>
#include <iostream>
#include <fstream>
#include <iomanip>

auto generate_report(){

    std::ofstream file("text.txt", std::ios::trunc);
    unsigned index{};
    auto test_array = mac::insert<unsigned >(nullptr, index, index, index);
    std::cout << "Array length"  << std::setw(25) <<"Seconds per insert\n";


    for(unsigned i{}; i < 60; ++i){
        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        for(auto add{0}; add < 1000; ++add, ++index) {
            test_array = mac::insert(test_array, index, index, index);
        }

        std::chrono::duration<double> fp_ms = std::chrono::system_clock::now() - start;

        std::cout << std::right << std::setw(12) << index  << std::right << std::setw(24) << fp_ms.count() << '\n';
    }
    std::cout << "done.\n";
}


int main(int argc, char const **argv) {
    auto session = Catch::Session();

    auto r = session.run(argc, argv);

    generate_report();
    return r;
}
