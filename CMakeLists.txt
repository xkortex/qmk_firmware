cmake_minimum_required(VERSION 2.8.3)
project(qmk_keyboard C)

message("Project ROOT ${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(keyboards)
add_subdirectory(keyboards/mitosis)

add_executable(mitosis_datagrok.out
        keyboards/mitosis/mitosis.c
        )



