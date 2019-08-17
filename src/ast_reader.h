/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef CIANA_ASTREADER_H
#define CIANA_ASTREADER_H

#include <vector>

namespace Ciana {

class ASTReader {
 public:
  ASTReader() {}
  virtual ~ASTReader() {}
  virtual bool initialize() = 0;
  virtual bool get_used_locations(Location input, std::vector<Location> &output) = 0;
  virtual bool get_impact_variables(Location input, std::vector<Location> &output) = 0;
  virtual bool get_impact_funtions(Location input, std::vector<Location> &output) = 0;
};

}  // namespace Ciana
#endif /*  CIANA_ASTREADER_H */
