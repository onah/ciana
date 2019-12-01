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
    URL https://
https://github.com/google/googletest/archive/release-1.10.0.zip
