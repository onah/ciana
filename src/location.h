/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef CIANA_LOCATION_H
#define CIANA_LOCATION_H

#include <string>

namespace Ciana {

class Location {
 private:
  std::string filename;
  unsigned line;
  unsigned column;

 public:
  Location(std::string input_filename, unsigned input_line, unsigned input_column);
  Location(const Location &obj);
  Location &operator=(const Location &obj);

  void set_data(std::string, unsigned, unsigned);
  std::string get_filename() const;
  unsigned get_line() const;
  unsigned get_column() const;
  bool operator==(const Location &other) const;
};

}  // namespace Ciana

#endif /* CIANA_LOCATION_H */
