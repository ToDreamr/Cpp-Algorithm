cmake_minimum_required(VERSION 3.27)
project(Carl_Code)

set(CMAKE_CXX_STANDARD 17)
add_executable(
        build # 编译最终程序名
        cunion.h
        tree
        wangdao/stack.cpp
        wangdao/default.h
        wangdao/queue.cpp
        sort/my_sort.h
        sort/insert_sort.cpp
        #作为编译主函数目录
        tree/tree_travel.cpp
        vector_map/arrow.cpp
        #        linux/cptxt.c
)
