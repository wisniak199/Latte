#include <iostream>
#include <antlr4-runtime.h>
#include "LatteLexer.h"
#include "LatteParser.h"
#include "LatteLLVMVisitor.h"


int main(int argc, const char* argv[]) {
  std::ifstream stream;
  stream.open(argv[1]);
  antlr4::ANTLRInputStream input(stream);
  latte::LatteLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  latte::LatteParser parser(&tokens);

  latte::LatteLLVMVisitor visitor;
  visitor.visitProgram(parser.program());

  return 0;
}
