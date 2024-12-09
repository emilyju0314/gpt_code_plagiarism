llvm::Value *CreateTerm::notInjectionCase(
    KORECompositePattern *constructor, llvm::Value *val) {
  const KORESymbol *symbol = constructor->getConstructor();
  KORESymbolDeclaration *symbolDecl
      = Definition->getSymbolDeclarations().at(symbol->getName());
  llvm::StructType *BlockType = getBlockType(Module, Definition, symbol);
  llvm::Value *BlockHeader
      = getBlockHeader(Module, Definition, symbol, BlockType);
  int idx = 2;
  std::vector<llvm::Value *> children;
  for (auto &child : constructor->getArguments()) {
    llvm::Value *ChildValue;
    if (idx == 2 && val != nullptr) {
      ChildValue = val;
    } else {
      ChildValue = createAllocation(child.get()).first;
    }
    llvm::Type *ChildPtrType
        = llvm::PointerType::get(BlockType->elements()[idx], 0);
    if (ChildValue->getType() == ChildPtrType) {
      ChildValue = new llvm::LoadInst(
          ChildValue->getType()->getPointerElementType(), ChildValue, "",
          CurrentBlock);
    }
    children.push_back(ChildValue);
    idx++;
  }
  llvm::Value *Block = allocateTerm(BlockType, CurrentBlock);
  llvm::Value *BlockHeaderPtr = llvm::GetElementPtrInst::CreateInBounds(
      BlockType, Block,
      {llvm::ConstantInt::get(llvm::Type::getInt64Ty(Ctx), 0),
       llvm::ConstantInt::get(llvm::Type::getInt32Ty(Ctx), 0)},
      symbol->getName(), CurrentBlock);
  new llvm::StoreInst(BlockHeader, BlockHeaderPtr, CurrentBlock);
  idx = 2;
  for (auto &ChildValue : children) {
    llvm::Value *ChildPtr = llvm::GetElementPtrInst::CreateInBounds(
        BlockType, Block,
        {llvm::ConstantInt::get(llvm::Type::getInt64Ty(Ctx), 0),
         llvm::ConstantInt::get(llvm::Type::getInt32Ty(Ctx), idx++)},
        "", CurrentBlock);
    new llvm::StoreInst(ChildValue, ChildPtr, CurrentBlock);
  }

  auto BlockPtr
      = llvm::PointerType::getUnqual(getTypeByName(Module, BLOCK_STRUCT));
  auto bitcast = new llvm::BitCastInst(Block, BlockPtr, "", CurrentBlock);
  if (symbolDecl->getAttributes().count("binder")) {
    auto call = llvm::CallInst::Create(
        getOrInsertFunction(Module, "debruijnize", BlockPtr, BlockPtr), bitcast,
        "withIndices", CurrentBlock);
    setDebugLoc(call);
    return call;
  } else {
    return bitcast;
  }
}