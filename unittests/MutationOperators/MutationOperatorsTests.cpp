#include "MutationOperators/MutationOperator.h"
#include "MutationOperators/AddMutationOperator.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Value.h"

#include "gtest/gtest.h"

using namespace Mutang;
using namespace llvm;

static LLVMContext Ctx;

TEST(MutationOperators, AddMutationOperator) {
  ConstantInt *A = ConstantInt::get(Type::getInt32Ty(Ctx), 42, 0);
  ConstantInt *B = ConstantInt::get(Type::getInt32Ty(Ctx), 43, 0);

  ConstantFP *FA = ConstantFP::get(Ctx, APFloat(42.0f));
  ConstantFP *FB = ConstantFP::get(Ctx, APFloat(43.0f));

  AddMutationOperator mutationOperator;

  std::unique_ptr<BinaryOperator> Add(BinaryOperator::CreateAdd(A, B));
  EXPECT_EQ(true, mutationOperator.canBeApplied(*Add));

  std::unique_ptr<BinaryOperator> FAdd(BinaryOperator::CreateFAdd(FA, FB));
  EXPECT_EQ(true, mutationOperator.canBeApplied(*FAdd));
}