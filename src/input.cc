/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "input.h"
#include <cerrno>
#include <cstdlib>
#include <limits>
#include <string>

namespace Ciana {

static unsigned get_param_of_number(const char *arg) {
  long result;
  result = strtol(arg, nullptr, 10);
  if (result <= 0 || result > std::numeric_limits<int>::max()) {
    return 0;
  }
  return static_cast<unsigned>(result);
}

bool Input::set_data(int argc, const char **argv) {
  if (argc != 4) {
    return false;
  }

  filename = argv[1];
  line = get_param_of_number(argv[2]);
  column = get_param_of_number(argv[3]);
  return !(line == 0 || column == 0);
}

std::string Input::get_filename() { return filename; }

unsigned Input::get_line() { return line; }

unsigned Input::get_column() { return column; }

}  // namespace Ciana
