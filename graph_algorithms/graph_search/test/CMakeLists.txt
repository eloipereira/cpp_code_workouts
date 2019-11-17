cmake_minimum_required(VERSION 3.10)

#Locate GTest

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(exec_bfs_test graph_tests.cpp)
target_link_libraries(exec_bfs_test ${GTEST_LIBRARIES} pthread graph_lib)
