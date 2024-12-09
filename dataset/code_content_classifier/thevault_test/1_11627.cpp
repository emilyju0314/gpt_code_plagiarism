void irgen::emitStructMetadata(IRGenModule &IGM, StructDecl *structDecl) {
  // TODO: structs nested within generic types
  ConstantInitBuilder initBuilder(IGM);
  auto init = initBuilder.beginStruct();
  init.setPacked(true);

  bool isPattern;
  bool canBeConstant;
  if (structDecl->isGenericContext()) {
    GenericStructMetadataBuilder builder(IGM, structDecl, init);
    builder.layout();
    isPattern = true;
    canBeConstant = false;

    maybeEmitNominalTypeMetadataAccessFunction(structDecl, builder);
  } else {
    StructMetadataBuilder builder(IGM, structDecl, init);
    builder.layout();
    isPattern = false;
    canBeConstant = builder.canBeConstant();

    maybeEmitNominalTypeMetadataAccessFunction(structDecl, builder);
  }

  CanType declaredType = structDecl->getDeclaredType()->getCanonicalType();

  // For now, all type metadata is directly stored.
  bool isIndirect = false;

  IGM.defineTypeMetadata(declaredType, isIndirect, isPattern,
                         canBeConstant, init.finishAndCreateFuture());
}