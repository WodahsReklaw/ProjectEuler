cmake_minimum_required(VERSION 3.5.0)

project(ProjectEuler CXX)

SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)

# Use C++17 since its good to prepare for the __future__.
set(CMAKE_CXX_STANDARD 14)
# Include symbols in executables, include all warning info.
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Include our source and header files into a library
# called project_lib.
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
include_directories(include)
include_directories(src)


file(GLOB PROJECT_SRCS ${PROJECT_SOURCE_DIR}/*.cpp)

MESSAGE(STATUS "PROJECT_SRCS:         " ${PROJECT_SRCS} )
add_library(project_lib ${PROJECT_SRCS})
set_target_properties(project_lib PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(bin)
