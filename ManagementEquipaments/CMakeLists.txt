cmake_minimum_required(VERSION 3.6)   # CMake version check
project(managementequipaments)               # Create project "ManagementEquipaments"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

set(SOURCE_FILES main.c)            # Add main.cpp file of project root directory as source file
add_executable(managementequipaments ${SOURCE_FILES})       # Add executable target with source files listed in SOURCE_FILES variable