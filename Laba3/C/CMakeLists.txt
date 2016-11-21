cmake_minimum_required(VERSION 3.6)
project(Project3)

set(CMAKE_CX_FLAGS "${CMAKE_CX_FLAGS} -std=c90")

set(SOURCE_FILES main.c)
add_executable(Project3 ${SOURCE_FILES})
target_link_libraries(Project3 m )