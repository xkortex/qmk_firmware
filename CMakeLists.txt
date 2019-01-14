cmake_minimum_required(VERSION 3.10)
project(qmk_firmware C)


add_executable(foobar.out
        keyboards/mitosis/mitosis.c
        keyboards/mitosis/mitosis.h
        )



#message("Project ROOT ${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(/usr/lib/avr
        /usr/lib/avr/include
        )

FIND_LIBRARY(avr_LIBRARIES avr /usr/lib/avr)

add_subdirectory(keyboards)
add_subdirectory(lib)
#
#add_executable(mitosis_ubergrok.out
#        keyboards/mitosis/mitosis.c
#        )
