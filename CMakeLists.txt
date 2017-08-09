cmake_minimum_required(VERSION 3.0.0)
project("lily-mkdir")

include_directories("${CMAKE_INSTALL_PREFIX}/include/lily/")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/src")

add_library(mkdir SHARED src/lily_mkdir.c)
set_target_properties(mkdir PROPERTIES PREFIX "")
