cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(AERSP424_HW1) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
add_executable(${CMAKE_PROJECT_NAME} plane_data_storage.cpp) # source files