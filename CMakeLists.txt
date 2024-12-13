cmake_minimum_required(VERSION 3.27)
project(Carl_Code)

set(CMAKE_CXX_STANDARD 17)
add_executable(
        build # 编译最终程序名
        cunion.h
        tree
        Algorithm/sort/my_sort.h
        Algorithm/sort/insert_sort.cpp
        #作为编译主函数目录
        tree/tree_travel.cpp
        Cpp_Test/arrow.cpp
        Cpp_Test/Person.cpp
        DataStructure/Graph/graph.c
        DataStructure/Graph/graph.h
        Algorithm/sort/heap_sort.cpp
)
