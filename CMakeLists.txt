cmake_minimum_required(VERSION 3.6)
project(listeC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp pList.h seqList.h indexList.h)
add_executable(listeC ${SOURCE_FILES})