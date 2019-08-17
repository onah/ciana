/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "location.h"

namespace Ciana {

Location::Location(std::string input_filename,
  unsigned input_line, unsigned input_column) {
  filename = input_filename;
  line = input_line;
  column = input_column;
}

Location::Location(const Location &obj) {
  filename = obj.get_filename();
  line = obj.get_line();
  column = obj.get_column();
}


Location &Location::operator=(const Location &obj) {
  filename = obj.get_filename();
  line = obj.get_line();
  column = obj.get_column();

  return (*this);
}

void Location::set_data(std::string input_filename, unsigned input_line,
                      unsigned input_column) {
  filename = input_filename;
  line = input_line;
  column = input_column;
}

std::string Location::get_filename() const {
  return filename;
}

unsigned Location::get_line() const {
  return line;
}

unsigned Location::get_column() const {
  return column;
}

bool Location::operator==(const Location &other) const {
  if (filename == other.get_filename() &&
      line == other.get_line() &&
      column == other.get_column()) {
    return true;
  }
  return false;
}

}  // namespace Ciana
