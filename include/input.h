/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef INPUT_H
#define INPUT_H

#include <string>

namespace Ciana {

class Input {
 private:
  std::string filename;
  unsigned line{0};
  unsigned column{0};

 public:
  std::string get_filename();
  bool  set_data(int argc, const char **argv);
  unsigned  get_line();
  unsigned  get_column();
};

}  // namespace Ciana

#endif // INPUT_H

