cmake_minimum_required(VERSION 3.6)
project (liblufa_usb)

#add_library(avr /usr/lib/avr/)
#find_package(avr REQUIRED)

include_directories(/usr/lib/avr
        /usr/lib/avr/include
        ${CMAKE_SOURCE_DIR}/lib/LUFA)

FIND_LIBRARY(avr_LIBRARIES avr /usr/lib/avr)

add_subdirectory(Core)

#target_link_libraries(LyrebirdFirmware ${avr_LIBRARIES})
