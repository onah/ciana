/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "ast_reader_libclang.h"
#include "ast_reader_creater.h"

namespace Ciana {

std::unique_ptr<ASTReader> ASTReaderCreater::create() {
  std::unique_ptr<ASTReader> creater(new ASTReaderLibClang());
  return creater;
}

}
