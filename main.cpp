#include "benchmarking.h"
#include <catch2/catch_session.hpp>

int main(int argc, char const **argv) {

    int r{};
    auto session = Catch::Session();
    // explicit scope
	{
        benchmarking bm;
        r = session.run(argc, argv);
    }
    return r;
}
