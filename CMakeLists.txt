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
        王道数据结构栈和队列/question.cpp
)
