llvm::Constant *CreateStaticTerm::notInjectionCase(
    KORECompositePattern *constructor, llvm::Constant *val) {
  const KORESymbol *symbol = constructor->getConstructor();
  llvm::StructType *BlockType = getBlockType(Module, Definition, symbol);

  std::stringstream koreString;
  constructor->print(koreString);
  llvm::Constant *Block
      = Module->getOrInsertGlobal(koreString.str().c_str(), BlockType);
  llvm::GlobalVariable *globalVar = llvm::dyn_cast<llvm::GlobalVariable>(Block);

  if (!globalVar->hasInitializer()) {
    std::vector<llvm::Constant *> blockVals;

    llvm::StructType *BlockHeaderType
        = getTypeByName(Module, BLOCKHEADER_STRUCT);
    uint64_t headerVal
        = getBlockHeaderVal(Module, symbol, BlockType) | NOT_YOUNG_OBJECT_BIT;
    llvm::Constant *BlockHeader = llvm::ConstantStruct::get(
        BlockHeaderType,
        llvm::ConstantInt::get(
            llvm::Type::getInt64Ty(Module->getContext()), headerVal));
    blockVals.push_back(BlockHeader);

    llvm::ArrayType *EmptyArrayType
        = llvm::ArrayType::get(llvm::Type::getInt64Ty(Module->getContext()), 0);
    blockVals.push_back(llvm::ConstantArray::get(
        EmptyArrayType, llvm::ArrayRef<llvm::Constant *>()));

    int idx = 2;
    for (auto &child : constructor->getArguments()) {
      llvm::Constant *ChildValue;
      if (idx++ == 2 && val != nullptr) {
        ChildValue = val;
      } else {
        ChildValue = (*this)(child.get()).first;
      }
      blockVals.push_back(ChildValue);
    }

    globalVar->setInitializer(llvm::ConstantExpr::getBitCast(
        llvm::ConstantStruct::get(BlockType, blockVals), BlockType));
  }

  std::vector<llvm::Constant *> Idxs
      = {llvm::ConstantInt::get(llvm::Type::getInt64Ty(Ctx), 0)};
  return llvm::ConstantExpr::getBitCast(
      llvm::ConstantExpr::getInBoundsGetElementPtr(BlockType, globalVar, Idxs),
      llvm::PointerType::getUnqual(getTypeByName(Module, BLOCK_STRUCT)));
}