/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef ANALYZER_H
#define ANALYZER_H

#include "ast_reader.h"
#include "input.h"
#include "location.h"
#include <memory>
#include <string>
#include <vector>

namespace Ciana {

class Analyzer {
 private:
  std::vector<Location> impact_objects;
  std::unique_ptr<ASTReader> ast_reader;
  bool has_impact(Location target);

 public:
  Analyzer(){}
  bool run(Input input);
  std::vector<Location> get_impact_objects();
};

}  // namespace Ciana

#endif // ANALYZER_H
