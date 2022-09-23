//
// Created by snizzfox on 9/21/22.
//

#include <iostream>
#include "benchmarking.h"

benchmarking::~benchmarking() {
//    auto final_time = std::chrono::system_clock::now() - start;
    std::chrono::duration<double, std::milli> fp_ms = std::chrono::system_clock::now() - start;

    std::cout << "time eplased in milli seconds: " << fp_ms.count() << '\n';
}

benchmarking::benchmarking(): start{std::chrono::system_clock::now()} {

}

benchmarking::benchmarking(benchmarking && other) noexcept {
    other.start = start;
}
