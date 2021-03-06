#pragma once

#include <llvm/Object/ObjectFile.h>

#include <string>

namespace mull {
  class MullModule;
  class MutationPoint;

  class ObjectCache {
    bool useOnDiskCache;
    std::string cacheDirectory;

  public:
    ObjectCache(bool useCache, const std::string &cacheDir);

    llvm::object::OwningBinary<llvm::object::ObjectFile> getObject(const MullModule &module);
    llvm::object::OwningBinary<llvm::object::ObjectFile> getObject(const MutationPoint &mutationPoint);

    void putObject(llvm::object::OwningBinary<llvm::object::ObjectFile> &object,
                   const MullModule &module);

    void putObject(llvm::object::OwningBinary<llvm::object::ObjectFile> &object,
                   const MutationPoint &mutationPoint);

  private:
    llvm::object::OwningBinary<llvm::object::ObjectFile> getObjectFromDisk(const std::string &identifier);
    void putObjectOnDisk(llvm::object::OwningBinary<llvm::object::ObjectFile> &object,
                         const std::string &identifier);
  };
}
