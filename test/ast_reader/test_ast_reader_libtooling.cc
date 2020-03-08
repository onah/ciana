#include "ast_reader_libtooling.h"
#include "location.h"
#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <vector>

class ASTReaderLibToolingTest : public ::testing::Test {
 protected:

  virtual void SetUp() {
    const std::string FileName = ".cianarc";
    std::ofstream File;
    File.open(FileName, std::ios::out);
    File << "../../../test/ciana_test/c_valiable_function/build/"
            "compile_commands.json"
         << std::endl;
  }

};

TEST_F(ASTReaderLibToolingTest, getUsedLocationsNormal) {

  Ciana::ASTReaderLibTooling AstReader;
  ASSERT_NO_FATAL_FAILURE(ASSERT_TRUE(AstReader.initialize() == true));
 
  Ciana::Location Input(
      "../../../test/ciana_test/c_valiable_function/src/multi.c", 10, 17);
  std::vector<Ciana::Location> Outputs;
  bool Result = AstReader.get_used_locations(Input, Outputs);
  ASSERT_EQ(true, Result);

  ASSERT_EQ(4, Outputs.size());

  // TODO; do test for filename

  ASSERT_EQ(8, Outputs[0].get_line());
  ASSERT_EQ(5, Outputs[0].get_column());

  ASSERT_EQ(8, Outputs[1].get_line());
  ASSERT_EQ(20, Outputs[1].get_column());

  ASSERT_EQ(10, Outputs[2].get_line());
  ASSERT_EQ(17, Outputs[2].get_column());

  ASSERT_EQ(11, Outputs[3].get_line());
  ASSERT_EQ(10, Outputs[3].get_column());

  return;
}

/* 
TEST_F(ASTReaderLibToolingTest, get) {
  Ciana::Location Input(
      "../../../test/ciana_test/c_valiable_function/src/multi.c", 10, 17);
  
  std::vector<Ciana::Location> Outputs;
  bool Result = AstReader.getImpactVariable(Input, Outputs);
  ASSERT_EQ(true, Result);

  ASSERT_EQ(1, Outputs.size());

  // TODO: ASSERT_EQ("../../../test/ciana_test/c_valiable_function/src/multi.c", Outputs.get_filename);
  ASSERT_EQ(10, Outputs[0].get_line());
  ASSERT_EQ(3, Outputs[0].get_column());
}
*/
