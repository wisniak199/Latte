#ifndef LATTE_LLVM_VISITOR
#define LATTE_LLVM_VISITOR

#include <iostream>
#include "antlr4-runtime.h"

#include "LatteParser.h"
#include "LatteBaseVisitor.h"


namespace latte {

class LatteLLVMVisitor : public LatteBaseVisitor {
public:
LatteLLVMVisitor();

virtual antlrcpp::Any visitProgram(LatteParser::ProgramContext *ctx) override;


};


}



#endif // LATTE_LLVM_VISITOR
