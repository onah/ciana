# CIANA = C/C++ Change Impact ANAlyzer
#
# Copyright (c) 2019 HANO Hiroyuki
#
# This software is released under MIT License,
# http://opensource.org/licenses/mit-license.php

cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE string "clang++ compiler" FORCE)
#set(CMAKE_CXX_FLAGS "-Werror -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")
set(CMAKE_CXX_FLAGS "-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE include-what-you-use)


add_executable(ciana
  src/main.cc
  src/input.cc
  src/output.cc
  src/analyzer.cc
  src/location.cc
  src/ast_reader_creater.cc
  src/ast_reader_libclang.cc
)

target_link_libraries(ciana
  clangSerialization
  clangASTMatchers
  clangAST
  clangFrontend
  clangTooling
  clangBasic
  LLVM
)
