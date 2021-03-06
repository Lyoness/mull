#pragma once

#include <cstdint>

namespace llvm {
  class Function;
  class Module;
  class Value;
}

namespace mull {
  struct InstrumentationInfo;

  extern "C" void mull_enterFunction(void **trampoline, uint64_t functionIndex);
  extern "C" void mull_leaveFunction(void **trampoline, uint64_t functionIndex);

  class Callbacks {
  public:
    Callbacks();
    void injectCallbacks(llvm::Function *function, uint64_t index, llvm::Value *infoPointer);
    llvm::Value *injectInstrumentationInfoPointer(llvm::Module *module,
                                                  const char *variableName);
  private:
  };
}
