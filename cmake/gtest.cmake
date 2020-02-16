# CIANA = C/C++ Change Impact ANAlyzer
#
# Copyright (c) 2019 HANO Hiroyuki
#
# This software is released under MIT License,
# http://opensource.org/licenses/mit-license.php

cmake_minimum_required(VERSION 3.3)

# Google Test settings
include(ExternalProject)

ExternalProject_Add(
    GoogleTest
    URL https://github.com/google/googletest/archive/release-1.10.0.zip
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    )

ExternalProject_Get_Property(GoogleTest source_dir)
set(GTEST_INCLUDE_PATH ${source_dir}/googletest/include)

ExternalProject_Get_Property(GoogleTest binary_dir)
set(GTEST_LIBRARY gtest)
add_library(${GTEST_LIBRARY} STATIC IMPORTED)
set_property(
    TARGET ${GTEST_LIBRARY}
    PROPERTY IMPORTED_LOCATION ${binary_dir}/lib/libgtest.a
    )
add_dependencies(${GTEST_LIBRARY} GoogleTest)

set(GTEST_MAIN_LIBRARY gtest_main)
add_library(${GTEST_MAIN_LIBRARY} STATIC IMPORTED)
set_property(
    TARGET ${GTEST_MAIN_LIBRARY}
    PROPERTY IMPORTED_LOCATION ${binary_dir}/lib/libgtest_main.a
    )


