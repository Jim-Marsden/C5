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

    for(unsigned i{}; i < 10000; ++i){
        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
        for(auto add{0}; add < 1000; ++add, ++index) {
            test_array = mac::insert(test_array, index, index, index);
        }

        std::chrono::duration<double> fp_ms = std::chrono::system_clock::now() - start;
        file  << index << std::setw(11) << ',' << std::setw(10) << fp_ms.count() << '\n';
//        std::cout  << index << std::setw(11) << ',' << std::setw(10) << fp_ms.count() << '\n';
    }
    std::cout << "done.\n";
}


int main(int argc, char const **argv) {



    int r{};
    auto session = Catch::Session();
    // explicit scope
	{
        r = session.run(argc, argv);
    }

    generate_report();
    return r;
}
