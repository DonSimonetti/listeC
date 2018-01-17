#cmake exclusive for examMain
cmake_minimum_required(VERSION 3.6)
project(listeC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES examMain.cpp examList.h scutils.h examRemoveFib.h)
add_executable(listeC ${SOURCE_FILES})