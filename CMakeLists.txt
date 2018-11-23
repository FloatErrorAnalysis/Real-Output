cmake_minimum_required(VERSION 3.8)
project(Real_Output)

set(CMAKE_CXX_STANDARD 11)
# include
include_directories(iRRAM/include /usr/local/include)
# link
link_libraries(${Real_Output_SOURCE_DIR}/iRRAM/lib/libiRRAM.a)
link_libraries(${Real_Output_SOURCE_DIR}/iRRAM/lib/libgmp.a)
link_libraries(${Real_Output_SOURCE_DIR}/iRRAM/lib/libmpfr.a)
set(SOURCE_FILES x/functions/error/error_sqrt_minus3.cpp)

add_executable(Real_Output ${SOURCE_FILES})