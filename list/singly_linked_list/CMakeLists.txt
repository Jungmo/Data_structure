cmake_minimum_required(VERSION 3.5)
project(singly_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.c
    slist.c
    slist.h)

add_executable(singly_linked_list ${SOURCE_FILES})