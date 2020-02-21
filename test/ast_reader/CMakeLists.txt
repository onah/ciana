set(MY_BINARY_NAME "test_ast_reader")

add_executable(${MY_BINARY_NAME}
  test_ast_reader_libtooling.cc
  ${PROJECT_SOURCE_DIR}/src/location.cc
  ${PROJECT_SOURCE_DIR}/src/ast_reader.cc
  ${PROJECT_SOURCE_DIR}/src/ast_reader_libtooling.cc
  )


#message(STATUS "GTEST_INCLUDE_PATH is ${GTEST_INCLUDE_PATH}")

target_include_directories(${MY_BINARY_NAME} PUBLIC
  ${GTEST_INCLUDE_PATH}
  ${CLANG_INCLUDE_DIRS}
  )

target_link_libraries(${MY_BINARY_NAME}
  gtest
  gtest_main
  pthread
  clangSerialization
  clangASTMatchers
  clangAST
  clangTooling
  clangFrontend
  clangBasic
  LLVM
)

add_test(
  NAME ${MY_BINARY_NAME}
  COMMAND $<TARGET_FILE:${MY_BINARY_NAME}>
  )


