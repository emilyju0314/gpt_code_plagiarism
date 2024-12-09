llvm::Value *irgen::emitParentMetadataRef(IRGenFunction &IGF,
                                          NominalTypeDecl *decl,
                                          llvm::Value *metadata) {
  auto slot = emitAddressOfParentMetadataSlot(IGF, metadata, decl);
  return IGF.emitInvariantLoad(slot);
}