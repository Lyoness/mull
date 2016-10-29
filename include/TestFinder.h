#pragma once

#include "MutationPoint.h"
#include "Test.h"

namespace llvm {

class Function;

}

namespace Mutang {

class Context;
class MutationOperator;

typedef std::pair<llvm::Function *, int> Testee;

class TestFinder {
public:
  virtual std::vector<std::unique_ptr<Test>> findTests(Context &Ctx) = 0;
  //virtual std::vector<llvm::Function *> findTestees(Test *Test, Context &Ctx) = 0;
  virtual std::vector<Testee> findTestees(Test *Test, Context &Ctx) = 0;
  virtual std::vector<std::unique_ptr<MutationPoint>> findMutationPoints(
                            std::vector<MutationOperator *> &MutationOperators,
                            llvm::Function &F) = 0;
  virtual std::vector<MutationPoint *> findMutationPoints(llvm::Function &F) {
    return std::vector<MutationPoint *>();
  }

  virtual ~TestFinder() {}
};

}