cmake_minimum_required(VERSION 3.4)

add_library(square STATIC square.cpp square.hpp)
target_include_directories(square PUBLIC ${CMAKE_CURRENT_LIST_DIR})
