/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include "location.h"
#include <string>
#include <vector>

namespace Ciana {

class Output {
public:
  void run(const std::vector<Location> &cursors);
  std::string get_strings_of_line(const std::string &file, unsigned line);
};

}  // namespace Ciana

#endif // OUTPUT_H
