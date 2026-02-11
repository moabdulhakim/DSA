cmake_minimum_required(VERSION 3.30)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(Data_Structures ${SRC_FILES})
