#include "ast_reader_libtooling.h"
#include "location.h"
#include <gtest/gtest.h>

#include <fstream>
#include <iostream>

TEST(get_used_locations_Test, normal) {

  const std::string FileName = ".cianarc";
  std::ofstream File;
  File.open(FileName, std::ios::out);
  File << "../../../test/ciana_test/c_valiable_function/build/"
          "compile_commands.json"
       << std::endl;

  Ciana::ASTReaderLibTooling AstReader;

  ASSERT_NO_FATAL_FAILURE(ASSERT_TRUE(AstReader.initialize() == true));

  Ciana::Location Input(
      "../../../test/ciana_test/c_valiable_function/src/multi.c", 10, 18);
  std::vector<Ciana::Location> Output;
  bool Result = AstReader.get_used_locations(Input, Output);
  ASSERT_EQ(true, Result);

  ASSERT_EQ(4, Output.size());

  // TODO; do test for filename

  ASSERT_EQ(8, Output[0].get_line());
  ASSERT_EQ(5, Output[0].get_column());

  ASSERT_EQ(8, Output[1].get_line());
  ASSERT_EQ(21, Output[1].get_column());

  ASSERT_EQ(10, Output[2].get_line());
  ASSERT_EQ(18, Output[2].get_column());

  ASSERT_EQ(11, Output[3].get_line());
  ASSERT_EQ(10, Output[3].get_column());

  return;
}
