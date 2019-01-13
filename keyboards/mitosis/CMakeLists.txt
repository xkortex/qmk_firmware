cmake_minimum_required(VERSION 2.8.3)
project(mitosis C)

find_library(qmk_LUFA qmk_LUFA lib/lufa)

add_library(mitosis_ubergrok
        config.h
        matrix.c
        mitosis.c
        mitosis.h
        keymaps/ubergrok/config.h
        keymaps/ubergrok/keymap.c
        )