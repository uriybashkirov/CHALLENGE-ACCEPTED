cmake_minimum_required(VERSION 3.6)
project(unti)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90 -Wall -Werror -pedantic ")

set(SOURCE_FILES Variant69.c)
add_executable(unti ${SOURCE_FILES})
target_link_libraries(unti m)
