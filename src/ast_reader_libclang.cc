/**
CIANA - C/C++ Change Impact ANAlyzer

Copyright (c) 2019 HANO Hiroyuki

This software is released under MIT License,
http://opensource.org/licenses/mit-license.php
*/

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include "ast_reader_libclang.h"
#include "location.h"
#include <string>

namespace Ciana {

class ASTCursor {
private:
  Location location;
  std::string name;
  int64_t id;

public:
  ASTCursor(Location location, std::string name, int64_t id);
  int64_t get_id();
  Location get_location();
};

ASTCursor::ASTCursor(Location in_location, std::string in_name, int64_t in_id)
:location(in_location), name(in_name), id(in_id)
{
}

int64_t ASTCursor::get_id() {
  return id;
}

Location ASTCursor::get_location() {
  return location;
}


class ASTCursorList {
private:
  std::vector<ASTCursor> cursor_list;

public:
  unsigned search_id(std::string filename, unsigned line, unsigned column);
  void push(ASTCursor input);
};

unsigned ASTCursorList::search_id(std::string filename, unsigned line, unsigned column) {
  //TODO
  (void)filename;
  (void)line;
  (void)column;
  for (auto itr = cursor_list.begin(); itr != cursor_list.end(); ++itr) {
  }
  return 0;
}

class GetCursor : public clang::ast_matchers::MatchFinder::MatchCallback {
private:
  unsigned line;
  unsigned column;
  std::string name;
  int64_t id;
public:
  virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &);
  void set_cursor(unsigned line, unsigned column);
  std::string get_name();
  int64_t get_id();
};

void GetCursor::set_cursor(unsigned in_line, unsigned in_column) {
  line = in_line;
  column = in_column;
}

void GetCursor::run(
  const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  clang::ASTContext *Context = Result.Context;
  const clang::DeclRefExpr *DRE =
      Result.Nodes.getNodeAs<clang::DeclRefExpr>("declrefexpr");

  if (DRE) {
    clang::SourceManager &sm = Context->getSourceManager();

    //StringRef work_filename = sm.getFilename(DRE->getLocation());
    unsigned work_line = sm.getExpansionLineNumber(DRE->getLocation());
    unsigned work_column = sm.getExpansionColumnNumber(DRE->getLocation());

    if (line == work_line && column == work_column) {
        name = DRE->getNameInfo().getName().getAsString();

        const clang::ValueDecl *vd = DRE->getDecl();
        id = vd->getID();
    }
  }
}

int64_t GetCursor::get_id() {
  return id;
}

class UsedLocation : public clang::ast_matchers::MatchFinder::MatchCallback {
private:
  const int64_t search_id;
  std::vector<ASTCursor> output;
public:
  UsedLocation(const int64_t id);
  virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &);
  std::vector<ASTCursor>  get_output();
};

UsedLocation::UsedLocation(const int64_t id)
:search_id(id) { 
}

void UsedLocation::run(
  const clang::ast_matchers::MatchFinder::MatchResult &Result) {

  clang::ASTContext *Context = Result.Context;
  const clang::DeclRefExpr *DRE =
      Result.Nodes.getNodeAs<clang::DeclRefExpr>("declrefexpr");

  if (DRE) {
    const clang::ValueDecl *vd = DRE->getDecl();
    int64_t local_id = vd->getID();

    if (local_id == search_id) {
      clang::SourceManager &sm = Context->getSourceManager();
      llvm::StringRef work_filename = sm.getFilename(DRE->getLocation());
      unsigned work_line = sm.getExpansionLineNumber(DRE->getLocation());
      unsigned work_column = sm.getExpansionColumnNumber(DRE->getLocation());
      std::string name = DRE->getNameInfo().getName().getAsString();

      Location loc(work_filename, work_line, work_column);
      ASTCursor cursor(loc, name, local_id);
      output.push_back(cursor);
    }
  }
}

std::vector<ASTCursor> UsedLocation::get_output() {
  return output;
}

bool ASTReaderLibClang::initialize() {
  llvm::StringRef filepath;
  filepath =
      "../test/sample1/build/compile_commands.json";

  std::string ErrorMessage;

  compdb = std::unique_ptr<clang::tooling::JSONCompilationDatabase>(
      clang::tooling::JSONCompilationDatabase::loadFromFile(
      filepath, ErrorMessage,
      clang::tooling::JSONCommandLineSyntax::AutoDetect));

  if (!compdb) {
    llvm::errs() << ErrorMessage;
    return false;
  }

  return true;
}

bool ASTReaderLibClang::get_used_locations(Location input, std::vector<Location> &output) {

  clang::ast_matchers::StatementMatcher declRefExprMatcher =
    clang::ast_matchers::declRefExpr().bind("declrefexpr");

  // TODO err -> llvm::ArrayRef<std::string> source_paths(input.get_filename());
  std::string tmp = input.get_filename();
  llvm::ArrayRef<std::string> source_paths(tmp);
  
  clang::tooling::ClangTool Tool(*compdb, source_paths);

  GetCursor cursor_getter;
  clang::ast_matchers::MatchFinder finder;
  finder.addMatcher(declRefExprMatcher, &cursor_getter);

  cursor_getter.set_cursor(input.get_line(), input.get_column());

  if (Tool.run(clang::tooling::newFrontendActionFactory(&finder).get()) == 0) {
    clang::tooling::ClangTool Tool2(*compdb, source_paths);
    int64_t id = cursor_getter.get_id();
    UsedLocation used_location(id);
    clang::ast_matchers::MatchFinder finder2;
    finder2.addMatcher(declRefExprMatcher, &used_location);

    if (Tool2.run(clang::tooling::newFrontendActionFactory(&finder2).get()) == 0) {
      std::vector<ASTCursor> resutls;
      resutls = used_location.get_output();

      for (auto itr = resutls.begin(); itr != resutls.end(); ++itr) {
        Location loc = (*itr).get_location();
        output.push_back(loc);
      }
      return true;
    }
  }

  return false;
}

bool ASTReaderLibClang::get_impact_variables(Location input, std::vector<Location> &results) {
  //TODO
  (void)input;
  (void)results;

  //clang::ast_matchers::StatementMatcher SampleMatcher =
    //binaryOperator(hasOperatorName("=")).bind("binOpe");

  std::string tmp = input.get_filename();
  llvm::ArrayRef<std::string> source_paths(tmp);
  
  clang::tooling::ClangTool Tool(*compdb, source_paths);

  //if (Tool.run(clang::tooling::newFrontendActionFactory(&finder).get()) == 0) {
  //}

// llvm::outs() << DRE->getOpcodeStr() << "\n";
    // llvm::outs() << "--- getLHS\n";
    // DRE->getLHS()->dump(Context->getSourceManager());
    // llvm::outs() << "--- getRHS\n";
    // DRE->getRHS()->dump(Context->getSourceManager());

  return true;
}

bool ASTReaderLibClang::get_impact_funtions(Location input, std::vector<Location> &results) {
  //TODO
  (void)input;
  (void)results;
  return true;
}

}  // namespace Ciana
