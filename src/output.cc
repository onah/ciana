/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "output.h"
#include "location.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace Ciana {

std::string Output::get_strings_of_line(std::string file, unsigned line) {
  std::ifstream ifs(file);
  if (!ifs) {
    return "";
  }

  std::string buf;
  unsigned count = 0;
  while (std::getline(ifs, buf)) {
    count++;
    if (count == line) {
      return buf;
    }
  }

  return "";
}

void Output::run(std::vector<Location> cursors) {
  for (auto itr = cursors.begin(); itr != cursors.end(); ++itr) {
    // std::string name = (*itr).get_name();
    std::string filename = (*itr).get_filename();
    unsigned line = (*itr).get_line();
    unsigned column = (*itr).get_column();

    std::cout << filename << "|" << line << " col " << column << "|";
    std::cout << get_strings_of_line(filename, line) << std::endl;
  }
  return;
}

}  // namespace Ciana
