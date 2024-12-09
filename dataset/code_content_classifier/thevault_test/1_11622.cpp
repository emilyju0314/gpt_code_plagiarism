llvm::Function *irgen::getOrCreateTypeMetadataAccessFunction(IRGenModule &IGM,
                                                             CanType type) {
  type = getRuntimeReifiedType(IGM, type);

  assert(!type->hasArchetype() &&
         "cannot create global function to return dependent type metadata");

  switch (getTypeMetadataAccessStrategy(type)) {
  case MetadataAccessStrategy::PublicUniqueAccessor:
  case MetadataAccessStrategy::HiddenUniqueAccessor:
  case MetadataAccessStrategy::PrivateAccessor:
    return getTypeMetadataAccessFunction(IGM, type, NotForDefinition);
  case MetadataAccessStrategy::NonUniqueAccessor:
    return getTypeMetadataAccessFunction(IGM, type, ForDefinition);
  }
  llvm_unreachable("bad type metadata access strategy");
}