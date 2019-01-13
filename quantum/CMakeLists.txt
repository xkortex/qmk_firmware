cmake_minimum_required(VERSION 2.8.3)
project(quantum C)

#add_library(avr /usr/lib/avr/)
#find_package(avr REQUIRED)

include_directories(/usr/lib/avr
        /usr/lib/avr/include
        )

FIND_LIBRARY(avr_LIBRARIES avr /usr/lib/avr)

find_package(avr REQUIRED)

add_library(libquantum
        quantum/api.c
        quantum/api.h
        quantum/color.c
        quantum/color.h
        quantum/config_common.h
        quantum/dynamic_keymap.c
        quantum/dynamic_keymap.h
        quantum/dynamic_macro.h
        quantum/encoder.c
        quantum/encoder.h
        quantum/fauxclicky.c
        quantum/fauxclicky.h
        quantum/keycode_config.c
        quantum/keycode_config.h
        quantum/keymap.h
        quantum/keymap_common.c
        quantum/led_tables.c
        quantum/led_tables.h
        quantum/matrix.c
        quantum/pincontrol.h
        quantum/pointing_device.c
        quantum/pointing_device.h
        quantum/quantum.c
        quantum/quantum.h
        quantum/quantum_keycodes.h
        quantum/rgb.h
        quantum/rgb_matrix.c
        quantum/rgb_matrix.h
        quantum/rgb_matrix_drivers.c
        quantum/rgblight.c
        quantum/rgblight.h
        quantum/rgblight_list.h
        quantum/rgblight_reconfig.h
        quantum/rgblight_types.h
        quantum/send_string_keycodes.h
        quantum/variable_trace.c
        quantum/variable_trace.h
        quantum/version.h
        )

#target_link_libraries(libquantum avr)