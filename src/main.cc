/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "analyzer.h"
#include "location.h"
#include "input.h"
#include "output.h"

#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
  Ciana::Input input;
  if (!input.set_data(argc, argv)) {
    std::cout << "Usage: ciana <filename> <line> <column>" << std::endl;
    return 10;
  }

  Ciana::Analyzer analyzer;
  if (!analyzer.run(input)) {
    return 11;
  }

  Ciana::Output output;
  output.run(analyzer.get_impact_objects());

  return 0;
}
