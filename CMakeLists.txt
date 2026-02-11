cmake_minimum_required(VERSION 3.30)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 20)

add_executable(Data_Structures main.cpp
        headers/Array.cpp
        headers/Array.h
        headers/Linkedlist.cpp
        headers/Linkedlist.h
        headers/Node.cpp
        headers/Node.h
        headers/Stack.cpp
        headers/Stack.h
        headers/Queue.cpp
        headers/Queue.h
        headers/bstNode.cpp
        headers/bstNode.h
        headers/BST.cpp
        headers/BST.h)
