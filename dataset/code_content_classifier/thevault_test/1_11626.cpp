FunctionPointer irgen::emitVirtualMethodValue(IRGenFunction &IGF,
                                              llvm::Value *base,
                                              SILType baseType,
                                              SILDeclRef method,
                                              CanSILFunctionType methodType,
                                              bool useSuperVTable) {
  AbstractFunctionDecl *methodDecl
    = cast<AbstractFunctionDecl>(method.getDecl());

  // Find the vtable entry for this method.
  SILDeclRef overridden = IGF.IGM.getSILTypes().getOverriddenVTableEntry(method);

  // Find the metadata.
  llvm::Value *metadata;
  if (useSuperVTable) {
    auto instanceTy = baseType;
    if (auto metaTy = dyn_cast<MetatypeType>(baseType.getSwiftRValueType()))
      instanceTy = SILType::getPrimitiveObjectType(metaTy.getInstanceType());

    if (IGF.IGM.isResilient(instanceTy.getClassOrBoundGenericClass(),
                            ResilienceExpansion::Maximal)) {
      // The derived type that is making the super call is resilient,
      // for example we may be in an extension of a class outside of our
      // resilience domain. So, we need to load the superclass metadata
      // dynamically.

      metadata = emitClassHeapMetadataRef(IGF, instanceTy.getSwiftRValueType(),
                                          MetadataValueType::TypeMetadata);
      auto superField = emitAddressOfSuperclassRefInClassMetadata(IGF, metadata);
      metadata = IGF.Builder.CreateLoad(superField);
    } else {
      // Otherwise, we can directly load the statically known superclass's
      // metadata.
      auto superTy = instanceTy.getSuperclass();
      metadata = emitClassHeapMetadataRef(IGF, superTy.getSwiftRValueType(),
                                          MetadataValueType::TypeMetadata);
    }
  } else {
    if ((isa<FuncDecl>(methodDecl) && cast<FuncDecl>(methodDecl)->isStatic()) ||
        (isa<ConstructorDecl>(methodDecl) &&
         method.kind == SILDeclRef::Kind::Allocator)) {
      metadata = base;
    } else {
      metadata = emitHeapMetadataRefForHeapObject(IGF, base, baseType,
                                                  /*suppress cast*/ true);
    }
  }

  // Use the type of the method we were type-checked against, not the
  // type of the overridden method.
  auto sig = IGF.IGM.getSignature(methodType);

  auto declaringClass = cast<ClassDecl>(overridden.getDecl()->getDeclContext());

  auto methodInfo =
    IGF.IGM.getMetadataLayout(declaringClass).getMethodInfo(IGF, overridden);
  auto offset = methodInfo.getOffset();

  auto slot = IGF.emitAddressAtOffset(metadata, offset,
                                      sig.getType()->getPointerTo(),
                                      IGF.IGM.getPointerAlignment());
  auto fnPtr = IGF.emitInvariantLoad(slot);

  return FunctionPointer(fnPtr, sig);
}