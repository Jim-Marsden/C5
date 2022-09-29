cmake_minimum_required(VERSION 3.23)
project(C5)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
        )
FetchContent_MakeAvailable(fmt)


#
#FetchContent_Declare(plot
#        GIT_REPOSITORY https://github.com/fbbdev/plot.git
#        GIT_TAG master
#        )
#FetchContent_MakeAvailable(plot)

add_executable(C5 main.cpp hw_insert.cpp hw_insert.h benchmarking.cpp benchmarking.h tests/hw1_tests.cpp)
target_link_libraries(C5 PRIVATE Catch2::Catch2 fmt::fmt)

include(CTest)
include(Catch)
#catch_discover_tests(C5)
