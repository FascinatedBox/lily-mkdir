cmake_minimum_required(VERSION 3.0.0)
project("lily-mkdir")

include_directories("${CMAKE_INSTALL_PREFIX}/include/lily/")

add_library(mkdir SHARED lily_mkdir.c)
set_target_properties(mkdir PROPERTIES PREFIX "")
