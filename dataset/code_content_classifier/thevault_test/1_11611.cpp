llvm::Value *irgen::emitClassFieldOffset(IRGenFunction &IGF,
                                         ClassDecl *theClass,
                                         VarDecl *field,
                                         llvm::Value *metadata) {
  auto slot = emitAddressOfClassFieldOffset(IGF, metadata, theClass, field);
  return IGF.emitInvariantLoad(slot);
}