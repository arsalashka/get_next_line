cmake_minimum_required(VERSION 3.17)
project(get_next_line C)

set(CMAKE_C_STANDARD 99)
set(MY_FLAGS "-Wall -Wextra -Werror -D BUFFER_SIZE=16")

add_definitions(${MY_FLAGS})
add_executable(get_next_line get_next_line.c get_next_line.h get_next_line_utils.c main.c)