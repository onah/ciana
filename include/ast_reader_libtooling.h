/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef AST_READER_LIBTOOLING_H
#define AST_READER_LIBTOOLING_H

#include <vector>
#include <string>

#include "location.h"
#include "ast_reader.h"

#include "clang/Tooling/JSONCompilationDatabase.h"
#include "clang/Tooling/Tooling.h"

namespace Ciana {

class ASTReaderLibTooling : public ASTReader {
 private:
  std::unique_ptr<clang::tooling::CompilationDatabase> compdb;

 public:
  ~ASTReaderLibTooling() {}
  bool initialize();
  bool get_used_locations(Location input, std::vector<Location> &output);
  bool get_impact_variables(Location input, std::vector<Location> &output);
  bool get_impact_funtions(Location input, std::vector<Location> &output);
};

}  // namespace Ciana
#endif // AST_READER_LIBTOOLING_H
