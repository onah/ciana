/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef LOCATION_H
#define LOCATION_H

#include <string>

namespace Ciana {

class Location {
 private:
  std::string filename;
  unsigned line;
  unsigned column;

 public:
  ~Location() = default;
  Location(std::string input_filename, unsigned input_line, unsigned input_column);
  Location(const Location &obj);
  Location &operator=(const Location &obj);

  Location(Location&&) = default;
  Location& operator=(Location&&) = default;

  void set_data(std::string, unsigned, unsigned);
  std::string get_filename() const;
  unsigned get_line() const;
  unsigned get_column() const;
  bool is_same(const Location &other) const;

};

}  // namespace Ciana

#endif // LOCATION_H
