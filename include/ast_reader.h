/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef SRC_AST_READHER_H
#define SRC_AST_READHER_H

#include "location.h"
#include <vector>

namespace Ciana {

class ASTReader {
 public:
  virtual ~ASTReader();
  virtual bool initialize() = 0;
  virtual bool get_used_locations(Location input, std::vector<Location> &output) = 0;
  virtual bool get_impact_variables(Location input, std::vector<Location> &output) = 0;
  virtual bool get_impact_funtions(Location input, std::vector<Location> &output) = 0;
};

}  // namespace Ciana
#endif // SRC_AST_READHER_H
