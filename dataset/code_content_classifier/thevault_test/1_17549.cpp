uint64_t
PathProfilingPass::instrument(llvm::Module& module,
                              llvm::Function& function,
                              uint64_t functionID) {
  llvm::DenseMap<llvm::BasicBlock*, uint64_t> blockCount;
  LoopInfo& linfo = getAnalysis<LoopInfoWrapperPass>(function).getLoopInfo();
  if (countPaths(blockCount, linfo, function))
  {
    return 0;
  }

  llvm::Instruction* id = nullptr;
  auto* voidTy = Type::getVoidTy(function.getContext());
  auto* int64Ty = Type::getInt64Ty(function.getContext());
  llvm::ConstantInt* funcId = llvm::ConstantInt::get(int64Ty, functionID, false);
  BasicBlock& entry = function.getEntryBlock();

  for (auto& inst : entry)
  {
    if (EPPID == inst.getName())
    {
      id = &inst;
    }
  }
  assert(id);

  // goal: instrument at select instructions to minimize the execution of instrumented function
  // encoding was responsible for instrumenting EPPID
  // path profiling should now increment global table by EPPID
  // at all termination blocks

  // step 1: locate termination blocks
  uint64_t nPaths = blockCount[&entry];

  std::vector<llvm::BasicBlock*> terms;
  for (auto& bb : function)
  {
    if (blockCount[&bb] == 1 && llvm::succ_empty(&bb))
    {
      terms.push_back(&bb);
    }
  }

  auto countfunc = module.getOrInsertFunction("PaThPrOfIlInG_count",
    FunctionType::get(voidTy, {int64Ty, int64Ty}, false));

  // step 2: instrument
  for (llvm::BasicBlock* bb : terms)
  {
    Instruction* inst = bb->getFirstNonPHI();
    if (&entry == bb)
	{
	  // take the third instruction below id
	  Instruction* gep = entry.getInstList().getNext(id);
	  Instruction* store = entry.getInstList().getNext(gep);
	  inst = entry.getInstList().getNext(store);
	}

    IRBuilder<> builder(inst);
    auto* gep = builder.CreateInBoundsGEP(int64Ty, id, ConstantInt::get(int64Ty, 0));
    auto* temp = builder.CreateAlignedLoad(gep, 8);
    builder.CreateCall(countfunc, {funcId, temp});
  }

  return nPaths;
}