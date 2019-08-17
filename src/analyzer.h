/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef CIANA_ANALYZER_H
#define CIANA_ANALYZER_H

#include <vector>
#include <string>
#include <memory>
#include "location.h"
#include "ast_reader.h"
#include "input.h"

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

#endif /* CIANA_ANALYZER_H */
