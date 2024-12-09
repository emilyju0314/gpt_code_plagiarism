void irgen::emitClassMetadata(IRGenModule &IGM, ClassDecl *classDecl,
                              const StructLayout &layout,
                              const ClassLayout &fieldLayout) {
  assert(!classDecl->isForeign());

  // Set up a dummy global to stand in for the metadata object while we produce
  // relative references.
  ConstantInitBuilder builder(IGM);
  auto init = builder.beginStruct();
  init.setPacked(true);

  // TODO: classes nested within generic types
  bool isPattern;
  bool canBeConstant;
  if (classDecl->isGenericContext()) {
    GenericClassMetadataBuilder builder(IGM, classDecl, init,
                                        layout, fieldLayout);
    builder.layout();
    isPattern = true;
    canBeConstant = false;

    maybeEmitNominalTypeMetadataAccessFunction(classDecl, builder);
  } else {
    ClassMetadataBuilder builder(IGM, classDecl, init, layout, fieldLayout);
    builder.layout();
    isPattern = false;
    canBeConstant = builder.canBeConstant();

    maybeEmitNominalTypeMetadataAccessFunction(classDecl, builder);
  }

  CanType declaredType = classDecl->getDeclaredType()->getCanonicalType();

  // For now, all type metadata is directly stored.
  bool isIndirect = false;

  StringRef section{};
  if (classDecl->isObjC())
    section = "__DATA,__objc_data, regular";

  auto var = IGM.defineTypeMetadata(declaredType, isIndirect, isPattern,
                                    canBeConstant,
                                    init.finishAndCreateFuture(),
                                    section);

  // Add classes that don't require dynamic initialization to the
  // ObjC class list.
  if (IGM.ObjCInterop && !isPattern && !isIndirect &&
      !doesClassMetadataRequireDynamicInitialization(IGM, classDecl)) {
    // Emit the ObjC class symbol to make the class visible to ObjC.
    if (classDecl->isObjC()) {
      emitObjCClassSymbol(IGM, classDecl, var);
    }

    IGM.addObjCClass(var,
              classDecl->getAttrs().hasAttribute<ObjCNonLazyRealizationAttr>());
  }
}