cmake_minimum_required(VERSION 2.8.3)
project(qmk_keyboard C)
# Load catkin and all dependencies required for this package
# TODO: remove all from COMPONENTS that are not catkin packages.

message("Project ROOT ${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(keyboards)
add_subdirectory(keyboards/mitosis)



