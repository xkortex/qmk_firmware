cmake_minimum_required(VERSION 2.8.3)
project(quantum C)

#add_library(avr /usr/lib/avr/)
#find_package(avr REQUIRED)

include_directories(/usr/lib/avr
        /usr/lib/avr/include
        ${CMAKE_SOURCE_DIR}/lib/LUFA)

FIND_LIBRARY(avr_LIBRARIES avr /usr/lib/avr)


add_library(libquantum
        )