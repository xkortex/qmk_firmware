cmake_minimum_required(VERSION 2.8.3)
project(mitosis C)

message("Project ${CMAKE_PROJECT_NAME} ROOT ${CMAKE_CURRENT_SOURCE_DIR}")
message("Current Binary Dir        ${CMAKE_CURRENT_BINARY_DIR}")

set(__AVR__ AVR CACHE STRING "AVR value") # Configurable by user
set(ARCH AVR8 CACHE STRING "target architecture")
set(MCU atmega32u4)
set(BOOTLOADER caterina)
configure_file(keymaps/ubergrok/auto_config.h.in keymaps/ubergrok/auto_config.h)

find_library(qmk_LUFA qmk_LUFA lib/lufa)
include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}/keymaps/ubergrok/
        )

add_definitions(-DARCH=AVR8)

add_executable(mitosis_ubergrok.out
        config.h
        matrix.c
        mitosis.c
        mitosis.h
        keymaps/ubergrok/config.h
        keymaps/ubergrok/keymap.c
        keymaps/ubergrok/feature_layout_rotate.c
        keymaps/ubergrok/feature_layout_rotate.h
        keymaps/ubergrok/feature_cdeq.c
        keymaps/ubergrok/feature_cdeq.h
        )