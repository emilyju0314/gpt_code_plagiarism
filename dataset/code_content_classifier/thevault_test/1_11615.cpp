static llvm::Value *emitNominalMetadataRef(IRGenFunction &IGF,
                                           NominalTypeDecl *theDecl,
                                           CanType theType) {
  assert(!isa<ProtocolDecl>(theDecl));

  if (!theDecl->isGenericContext()) {
    assert(!IGF.IGM.isResilient(theDecl, ResilienceExpansion::Maximal));
    // TODO: If Obj-C interop is off, we can relax this to allow referencing
    // class metadata too.
    assert(isa<StructDecl>(theDecl) || isa<EnumDecl>(theDecl));
    return IGF.IGM.getAddrOfTypeMetadata(theType, false);
  }

  // We are applying generic parameters to a generic type.
  assert(theType->isSpecialized() &&
         theType->getAnyNominal() == theDecl);

  // Check to see if we've maybe got a local reference already.
  if (auto cache = IGF.tryGetLocalTypeData(theType,
                                           LocalTypeDataKind::forTypeMetadata()))
    return cache;

  // Grab the substitutions.
  GenericArguments genericArgs;
  genericArgs.collect(IGF, theType);
  assert(genericArgs.Values.size() > 0 && "no generic args?!");

  // Call the generic metadata accessor function.
  llvm::Function *accessor =
      IGF.IGM.getAddrOfGenericTypeMetadataAccessFunction(theDecl,
                                                         genericArgs.Types,
                                                         NotForDefinition);

  auto result = IGF.Builder.CreateCall(accessor, genericArgs.Values);
  result->setDoesNotThrow();
  result->addAttribute(llvm::AttributeList::FunctionIndex,
                       llvm::Attribute::ReadNone);

  IGF.setScopedLocalTypeData(theType, LocalTypeDataKind::forTypeMetadata(),
                             result);
  return result;
}