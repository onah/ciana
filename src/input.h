/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#pragma once

#include <string>

namespace Ciana {

class Input {
 private:
  std::string filename;
  unsigned line;
  unsigned column;

 public:
  Input() : filename(std::string("")), line(0), column(0){}
  bool set_data(int, char *[]);
  std::string get_filename();
  unsigned get_line();
  unsigned get_column();
};

}  // namespace Ciana
