#include "LatteLLVMVisitor.h"
#include <llvm/IR/LLVMContext.h>

using namespace latte;

LatteLLVMVisitor::LatteLLVMVisitor() {}

antlrcpp::Any LatteLLVMVisitor::visitProgram(LatteParser::ProgramContext *ctx) {
  std::cout << "siema" << std::endl;
  llvm::LLVMContext context;
  return visitChildren(ctx);
}
