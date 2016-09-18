cmake_minimum_required(VERSION 3.6)
project(Test_c)

set(CMAKE_C_FLAGS "${CMAKE_С_FLAGS} -std=c90 -Wall -Werror -pedantic")

set(SOURCE_FILES Listing1.c "Listing 2.c" "Listing 3.c" "Listing 4.c" "Listing 5.c" "Listing 6.c" "Listing 7.c" "Listing 8.c" "Listing 9.c" "Listing 10.c" "Listing 11.c" "Listing 12.c" "Listing 13.c" "Listing 14.c" "Listing 15.c" "Variant 69.c")
add_executable(Test_c ${SOURCE_FILES})
target_link_libraries(Test_c m)