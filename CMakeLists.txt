cmake_minimum_required(VERSION 3.28)

project(bill_app)

set(CMAKE_CXX_STANDARD 11)

# 包含头文件目录
include_directories(include)

# 添加源文件
add_executable(bill_app
    src/main.cpp
    src/menus.cpp
    src/operations.cpp
    src/read_input.cpp
)
