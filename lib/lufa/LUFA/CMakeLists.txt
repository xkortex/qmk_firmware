cmake_minimum_required(VERSION 3.6)
project (libqmk C)

#add_library(avr /usr/lib/avr/)
#find_package(avr REQUIRED)

include_directories(/usr/lib/avr
        /usr/lib/avr/include
        ${CMAKE_SOURCE_DIR}/lib/LUFA)

FIND_LIBRARY(avr_LIBRARIES avr /usr/lib/avr)

add_subdirectory(Drivers)


add_library(qmk_LUFA
        Common/Architectures.h
        Common/ArchitectureSpecific.h
        Common/Attributes.h
        Common/BoardTypes.h
        Common/Common.h
        Common/CompilerSpecific.h
        Common/Endianness.h
        )

set_target_properties(qmk_LUFA PROPERTIES LINKER_LANGUAGE C)
#target_link_libraries(LyrebirdFirmware ${avr_LIBRARIES})
