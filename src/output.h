/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef CIANA_OUTPUT_H
#define CIANA_OUTPUT_H

#include <vector>
#include <string>
#include "location.h"

namespace Ciana {

class Output {
public:
  void run(std::vector<Location>);
  std::string get_strings_of_line(std::string, unsigned);
};

}  // namespace Ciana

#endif /* CIANA_OUTPUT_H */
