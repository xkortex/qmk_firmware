cmake_minimum_required(VERSION 3.6)
project (liblufa_usb_core)

add_library(lufa_usb_core
        ConfigDescriptors.c
        ConfigDescriptors.h
        )