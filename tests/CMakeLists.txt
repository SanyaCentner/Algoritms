cmake_minimum_required(VERSION 3.16)

set(PROJECT_SOURCE_FILES ../src/func.cpp)

add_executable(tests test.cpp ${PROJECT_SOURCE_FILES})

include_directories(include)

target_link_libraries(tests gtest ${GTEST_LIBRARIES} pthread)