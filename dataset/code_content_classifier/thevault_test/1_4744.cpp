Value * PushExpr::CodeGen(Module *M, IRBuilder<> &B)
{
  LLVMContext &C = M->getContext();
  
  if (__Stack == NULL) {
#define kDefaultStackSize 16
    
    __Stack = B.CreateAlloca(Type::getInt64Ty(C)->getPointerTo());
    __Stack->setName("stack");
    Value *Stack = B.CreateAlloca(Type::getInt64Ty(C),
                                  B.getInt64(kDefaultStackSize));
    B.CreateStore(Stack, __Stack);
    
    __StackSize = B.CreateAlloca(Type::getInt64Ty(C));
    __StackSize->setName("stack.size");
    B.CreateStore(B.getInt64(kDefaultStackSize), __StackSize);
  }
  
  if (__StackIdx == NULL) {
    __StackIdx = B.CreateAlloca(Type::getInt64Ty(C));
    __StackIdx->setName("stack.index");
    B.CreateStore(B.getInt64(0), __StackIdx);
  }
  
  Value *Idx = B.CreateLoad(__StackIdx);
  
  Function *F = B.GetInsertBlock()->getParent();
  BasicBlock *RSBB = BasicBlock::Create(C, "ResizeStackBlock", F);
  BasicBlock *DoneBB = BasicBlock::Create(C, "DoneBlock", F);
  
  Value *ResGT = B.CreateICmpSGE(Idx, B.CreateLoad(__StackSize)); // If |Idx| >= |__StackSize|
  B.CreateCondBr(ResGT, RSBB, DoneBB);
  
  B.SetInsertPoint(RSBB);
  IRBuilder<> RSB(RSBB);
  
  // Add |kDefaultStackSize| to the stack size
  Value *NewSize = RSB.CreateAdd(Idx, RSB.getInt64(kDefaultStackSize));
  
#undef kDefaultStackSize
  
  // Alloc a new stack and copy from the old stack
  Value *NewStack = RSB.CreateAlloca(Type::getInt64Ty(C),
                                     NewSize);
  MemCpy(NewStack, RSB.CreateLoad(__Stack),
         RSB.CreateMul(RSB.CreateLoad(__StackSize), B.getInt64(8)), // Copy |__StackSize| * 8 bytes of memory
         M, RSB);
  RSB.CreateStore(NewStack, __Stack);
  
  RSB.CreateStore(NewSize, __StackSize);
  
  RSB.CreateBr(DoneBB);
  B.SetInsertPoint(DoneBB);
  
  
  Value *Ptr = B.CreateLoad(__Stack);// |_Stack| -> (i64*)*, |Ptr| -> i64*
  Value *Addr = B.CreateAdd(B.CreatePtrToInt(Ptr, Type::getInt64Ty(C)),
                            B.CreateMul(Idx, B.getInt64(8 /* 64 bits */)));
  Value *FinalPtr = B.CreateIntToPtr(Addr,
                                     Type::getInt64Ty(C)->getPointerTo());
  
  Value *V = _expr->CodeGen(M, B);
  B.CreateStore(B.CreatePtrToInt(V, Type::getInt64Ty(C)),
                FinalPtr);
  
  // Increment |__StackIdx|
  Value *NewIdx = B.CreateAdd(Idx, B.getInt64(1));
  B.CreateStore(NewIdx, __StackIdx);
  
  return NULL;
}