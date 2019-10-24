cmake_minimum_required(VERSION 3.8)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(hello main.cpp)
add_executable(insertion_sort src/01_foundations/02_getting_started/insertion_sort.cpp)
add_executable(selection_sort src/01_foundations/02_getting_started/selection_sort.cpp)
add_executable(merge_sort src/01_foundations/02_getting_started/merge_sort.cpp)
add_executable(maximum_subarray src/01_foundations/04_divide-and-conquer/maximum_subarray.cpp)
add_executable(maximum_subarray_linear src/01_foundations/04_divide-and-conquer/maximum_subarray_linear.cpp)