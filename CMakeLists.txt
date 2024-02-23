cmake_minimum_required(VERSION 3.28) # Specify CMake version.
project(HW_1_AERSP424) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # Specify C++ version.
include_directories(${CMAKE_SOURCE_DIR}/include) # header file folder.
add_executable(Problem1 main1.cpp)
add_executable(Problem2_5 main2_5.cpp Plane.cpp)
add_executable(Problem7 main7.cpp Plane.cpp Pilot.cpp)
add_executable(Problem8 main8.cpp Plane.cpp Pilot.cpp)

