Value * PopExpr::CodeGen(Module *M, IRBuilder<> &B)
{
  Value *Idx = B.CreateLoad(__StackIdx);
  Value *NewIdx = B.CreateSub(Idx, B.getInt64(1));
  B.CreateStore(NewIdx, __StackIdx);
  
  LLVMContext &C = M->getContext();
  
  Value *Ptr = B.CreateLoad(__Stack);
  Value *Addr = B.CreateAdd(B.CreatePtrToInt(Ptr,
                                             Type::getInt64Ty(C)),
                            B.CreateMul(NewIdx, B.getInt64(8)));
  Value *FinalPtr = B.CreateIntToPtr(Addr,
                                     Type::getInt64Ty(C)->getPointerTo());
  
  Value *V = B.CreateIntToPtr(B.CreateLoad(FinalPtr),
                              getObjPtrTy(C));
  
  string name = (cast<VarExpr>(_expr))->getName();
  InsertOrUpdate(CxxStrToVal(name, M, B),
                 V, M, B);
  
  return V;
}