llvm::Value *irgen::emitArgumentMetadataRef(IRGenFunction &IGF,
                                            NominalTypeDecl *decl,
                                      const GenericTypeRequirements &reqts,
                                            unsigned reqtIndex,
                                            llvm::Value *metadata) {
  assert(reqts.getRequirements()[reqtIndex].Protocol == nullptr);
  return emitLoadOfGenericRequirement(IGF, metadata, decl, reqtIndex,
                                      IGF.IGM.TypeMetadataPtrTy);
}