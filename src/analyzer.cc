/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include <vector>
#include <algorithm>
#include "analyzer.h"
#include "ast_reader.h"
#include "ast_reader_creater.h"
#include "location.h"
#include "input.h"

namespace Ciana {

bool Analyzer::has_impact(Location input) {
  std::vector<Location> results;

  std::vector<Location> used_locations;
  if (!ast_reader->get_used_locations(input, used_locations)) {
    return false;
  }
  results.insert(results.end(), used_locations.begin(), used_locations.end());

  std::vector<Location> impact_variables;
  if (!ast_reader->get_impact_variables(input, impact_variables)) {
    return false;
  }
  results.insert(results.end(), impact_variables.begin(), impact_variables.end());

  std::vector<Location> impact_functions;
  if (!ast_reader->get_impact_funtions(input, impact_functions)) {
    return false;
  }
  results.insert(results.end(), impact_functions.begin(), impact_functions.end());

  for (auto&& itr : results) {
    bool find = false;
    for (auto&& obj : impact_objects) {
      if (obj.is_same(itr)) {
        find = true;
        break;
      }
   }
   if (!find) {
    impact_objects.push_back(itr);
     bool ret = has_impact(itr);
      if (ret == false) {
        return false;
      }
    }
  }

  return true;
}

bool Analyzer::run(Input input) {

  ast_reader = ASTReaderCreater::create();
  if (!ast_reader->initialize()) {
    return false;
  }

  Location target(input.get_filename(), input.get_line(), input.get_column());
  bool ret = has_impact(target);
  return ret;
}

std::vector<Location> Analyzer::get_impact_objects() {
  return impact_objects;
}

}  // namespace Ciana
