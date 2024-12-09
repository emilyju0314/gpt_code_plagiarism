llvm::Value *CreateTerm::createFunctionCall(
    std::string name, KORECompositePattern *pattern, bool sret, bool fastcc) {
  std::vector<llvm::Value *> args;
  auto returnSort = dynamic_cast<KORECompositeSort *>(
      pattern->getConstructor()->getSort().get());
  auto returnCat = returnSort->getCategory(Definition);
  int i = 0;
  for (auto sort : pattern->getConstructor()->getArguments()) {
    auto concreteSort = dynamic_cast<KORECompositeSort *>(sort.get());
    llvm::Value *arg
        = createAllocation(pattern->getArguments()[i++].get()).first;
    switch (concreteSort->getCategory(Definition).cat) {
    case SortCategory::Map:
    case SortCategory::List:
    case SortCategory::Set: {
      if (!arg->getType()->isPointerTy()) {
        llvm::AllocaInst *AllocCollection
            = new llvm::AllocaInst(arg->getType(), 0, "", CurrentBlock);
        new llvm::StoreInst(arg, AllocCollection, CurrentBlock);
        args.push_back(AllocCollection);
      } else {
        args.push_back(arg);
      }
      break;
    }
    default: args.push_back(arg); break;
    }
  }
  return createFunctionCall(name, returnCat, args, sret, fastcc);
}