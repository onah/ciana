/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "analyzer.h"
#include "input.h"
#include "location.h"
#include "output.h"
#include <iostream>
#include <vector>
#include <array>

enum CianaError {
  NORMAL = 0,
  INPUT_ERROR = 10,
  ANALYZE_ERROR = 11,
};

int main(const int argc, const char **argv) {
  Ciana::Input input;

  if (!input.set_data(argc, argv)) {
    std::cout << "Usage: ciana <filename> <line> <column>" << std::endl;
    return CianaError::INPUT_ERROR;
  }

  Ciana::Analyzer analyzer;
  if (!analyzer.run(input)) {
    return CianaError::ANALYZE_ERROR;
  }

  Ciana::Output output;
  output.run(analyzer.get_impact_objects());

  return CianaError::NORMAL;
}
