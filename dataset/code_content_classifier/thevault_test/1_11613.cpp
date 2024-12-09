llvm::Constant *irgen::tryEmitConstantHeapMetadataRef(IRGenModule &IGM,
                                                      CanType type,
                                              bool allowDynamicUninitialized) {
  auto theDecl = type->getClassOrBoundGenericClass();
  assert(theDecl && "emitting constant heap metadata ref for non-class type?");

  // If the class must not require dynamic initialization --- e.g. if it
  // is a super reference --- then respect everything that might impose that.
  if (!allowDynamicUninitialized) {
    if (doesClassMetadataRequireDynamicInitialization(IGM, theDecl))
      return nullptr;

  // Otherwise, just respect genericity.
  } else if (theDecl->isGenericContext() && !isTypeErasedGenericClass(theDecl)){
    return nullptr;
  }

  // For imported classes, use the ObjC class symbol.
  // This incidentally cannot coincide with most of the awkward cases, like
  // having parent metadata.
  if (!hasKnownSwiftMetadata(IGM, theDecl))
    return IGM.getAddrOfObjCClass(theDecl, NotForDefinition);

  return IGM.getAddrOfTypeMetadata(type, false);
}