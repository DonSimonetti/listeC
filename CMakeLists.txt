cmake_minimum_required(VERSION 3.6)
project(listeC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES examMain.cpp pList.h seqList.h indexList.h)
add_executable(listeC ${SOURCE_FILES})