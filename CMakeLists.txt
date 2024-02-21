cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(HW_1_AERSP424) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
add_executable(Question1 plane_data_storage.cpp) # source files.
add_executable(Question2_5 main.cpp Plane.cpp)
