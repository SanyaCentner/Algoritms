cmake_minimum_required(VERSION 3.20)
project(Algoritms)

set(CMAKE_CXX_STANDARD 23)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
        gtest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(gtest)
set(GCC_COVERAGE_COMPILE_FLAGS "--coverage")

add_compile_options("--coverage")

add_link_options("--coverage")

enable_testing()

include_directories(include)

add_executable(Algoritms src/main.cpp src/func.cpp)

add_subdirectory(tests)