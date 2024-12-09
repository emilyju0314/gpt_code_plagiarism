static void emitPolymorphicParametersFromArray(IRGenFunction &IGF,
                                               NominalTypeDecl *typeDecl,
                                               Address array) {
  GenericTypeRequirements requirements(IGF.IGM, typeDecl);

  array = IGF.Builder.CreateElementBitCast(array, IGF.IGM.TypeMetadataPtrTy);

  auto getInContext = [&](CanType type) -> CanType {
    return typeDecl->mapTypeIntoContext(type)
             ->getCanonicalType();
  };

  // If we have a parent type, it's the first parameter.
  if (requirements.hasParentType()) {
    auto parentType = getInContext(requirements.getParentType());
    llvm::Value *parentMetadata = IGF.Builder.CreateLoad(array);
    array = IGF.Builder.CreateConstArrayGEP(array, 1, IGF.IGM.getPointerSize());
    IGF.bindLocalTypeDataFromTypeMetadata(parentType, IsExact, parentMetadata);
  }

  // Okay, bind everything else from the context.
  requirements.bindFromBuffer(IGF, array, getInContext);
}