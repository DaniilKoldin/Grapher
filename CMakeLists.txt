cmake_minimum_required(VERSION 3.22)
project(GRAPHER C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(GRAPHER
        src/parse_func.c
        src/rpn.c
        src/structs.c
        src/calc.c
        src/graph.c
        )

target_link_libraries(GRAPHER m)
