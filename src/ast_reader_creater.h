/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#ifndef CIANA_ASTREADER_CREATER_H
#define CIANA_ASTREADER_CREATER_H

#include <vector>
#include "ast_reader.h"

namespace Ciana {

class ASTReaderCreater {
public:
  static std::unique_ptr<ASTReader> create();
};

}  // namespace Ciana
#endif /*  CIANA_ASTREADER__CREATER_H */
