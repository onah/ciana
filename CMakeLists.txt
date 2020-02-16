# CIANA = C/C++ Change Impact ANAlyzer
#
# Copyright (c) 2019 HANO Hiroyuki
#
# This software is released under MIT License,
# http://opensource.org/licenses/mit-license.php

cmake_minimum_required(VERSION 3.3)

project(Ciana CXX)

#set(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE STRING "clang++ compiler" FORCE)
#set(CMAKE_CXX_FLAGS "-Werror -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")
#set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-warnings-as-errors=*;")
#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE include-what-you-use)

include_directories(include)
#include_directories(/usr/lib/llvm-9/include)
#link_directories(/usr/lib/llvm-9/lib)

# llvm/clang
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} in ${LLVM_INSTALL_PREFIX}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
find_package(Clang REQUIRED CONFIG HINTS "${LLVM_INSTALL_PREFIX}/lib/cmake/clang")
message(STATUS "Found Clang in ${CLANG_INSTALL_PREFIX}")

add_executable(ciana
  src/main.cc
  src/input.cc
  src/output.cc
  src/analyzer.cc
  src/location.cc
  src/ast_reader.cc
  src/ast_reader_creater.cc
  src/ast_reader_libtooling.cc
)

target_include_directories(ciana PUBLIC ${CLANG_INCLUDE_DIRS})

target_link_libraries(ciana PRIVATE
  clangSerialization
  clangASTMatchers
  clangAST
  clangTooling
  clangFrontend
  clangBasic
  LLVM
)

# testing
enable_testing()
include(cmake/gtest.cmake)
add_subdirectory(test)


