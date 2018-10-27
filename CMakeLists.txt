cmake_minimum_required(VERSION 3.8)
project(Real_Output)

set(CMAKE_CXX_STANDARD 11)
# include(include/)
include_directories(include)
set(SOURCE_FILES  functions/double/sqrt_minus.cpp)

add_executable(Real_Output ${SOURCE_FILES})