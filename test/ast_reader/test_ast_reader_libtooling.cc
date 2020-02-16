#include "ast_reader_libtooling.h"
#include "location.h"
#include <gtest/gtest.h>

#include <fstream>

TEST(get_used_locations_Test, normal) {

  const std::string FileName = ".cianarc";
  std::ofstream File;
  File.open(FileName, std::ios::out);
  File << "../../../test/ciana_test/c_valiable_function/build/compile_commands.json" << std::endl;

  Ciana::ASTReaderLibTooling ast_reader;

  ASSERT_NO_FATAL_FAILURE(
    ASSERT_TRUE(ast_reader.initialize() == true));

  Ciana::Location input("../../../test/ciana_test/c_valiable_function/src/multi.c", 10, 18);
  std::vector<Ciana::Location> output;
  bool result = ast_reader.get_used_locations(input, output);
  ASSERT_EQ(true, result);
}

