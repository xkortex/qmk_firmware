cmake_minimum_required(VERSION 3.6)
project (libqmk)

#add_library(avr /usr/lib/avr/)
#find_package(avr REQUIRED)

include_directories(/usr/lib/avr
        /usr/lib/avr/include
        ${CMAKE_SOURCE_DIR}/lib/LUFA)

FIND_LIBRARY(avr_LIBRARIES avr /usr/lib/avr)

add_subdirectory(lufa/LUFA)

add_library(qmk_lufa
        lufa/LUFA/Version.h
        )

set_target_properties(qmk_lufa PROPERTIES LINKER_LANGUAGE C)

#target_link_libraries(LyrebirdFirmware ${avr_LIBRARIES})
