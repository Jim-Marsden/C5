//
// Created by snizzfox on 9/21/22.
//

#ifndef C5_BENCHMARKING_H
#define C5_BENCHMARKING_H

#include <chrono>
#include <string>

class benchmarking {
public:
    ~benchmarking();
    benchmarking();

    benchmarking(benchmarking &&) noexcept ;

    benchmarking(benchmarking const &) = delete;

    benchmarking &operator=(benchmarking const &) = delete;
private:
    std::chrono::time_point<std::chrono::system_clock> start;
};


#endif //C5_BENCHMARKING_H
