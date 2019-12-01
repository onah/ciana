/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "location.h"
#include "output.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace Ciana {

std::string Output::get_strings_of_line(const std::string& file, unsigned line) {
  const std::string error_result;

  std::ifstream ifs(file, std::ios_base::in);
  if (!ifs) {
    return error_result;
  }

  std::string buf;
  unsigned count = 0;
  while (std::getline(ifs, buf)) {
    count++;
    if (count == line) {
      return buf;
    }
  }

  return error_result;
}

void Output::run(const std::vector<Location> &cursors) {
  for (const auto& e: cursors) {
    // std::string name = (*itr).get_name();
    std::string filename = e.get_filename();
    unsigned line = e.get_line();
    unsigned column = e.get_column();

    std::cout << filename << "|" << line << " col " << column << "|";
    std::cout << get_strings_of_line(filename, line) << std::endl;
  }
}

}  // namespace Ciana
