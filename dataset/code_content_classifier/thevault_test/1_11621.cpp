llvm::Value *IRGenFunction::emitTypeMetadataRef(CanType type) {
  type = getRuntimeReifiedType(IGM, type);

  if (type->hasArchetype() ||
      isTypeMetadataAccessTrivial(IGM, type)) {
    return emitDirectTypeMetadataRef(*this, type);
  }

  switch (getTypeMetadataAccessStrategy(type)) {
  case MetadataAccessStrategy::PublicUniqueAccessor:
  case MetadataAccessStrategy::HiddenUniqueAccessor:
  case MetadataAccessStrategy::PrivateAccessor:
    return emitCallToTypeMetadataAccessFunction(*this, type, NotForDefinition);
  case MetadataAccessStrategy::NonUniqueAccessor:
    return emitCallToTypeMetadataAccessFunction(*this, type, ForDefinition);
  }
  llvm_unreachable("bad type metadata access strategy");
}