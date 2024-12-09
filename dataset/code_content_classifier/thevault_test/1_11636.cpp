SILValue SILGenFunction::emitConversionFromSemanticValue(SILLocation loc,
                                                         SILValue semanticValue,
                                                         SILType storageType) {
  auto &destTL = getTypeLowering(storageType);
  (void)destTL;
  // Easy case: the types match.
  if (semanticValue->getType() == storageType) {
    return semanticValue;
  }
  
  // @weak types are never loadable, so we don't need to handle them here.
  
  // For @unowned types, place into an unowned box.
  if (auto unownedType = storageType.getAs<UnownedStorageType>()) {
    assert(unownedType->isLoadable(ResilienceExpansion::Maximal));
    (void) unownedType;

    SILValue unowned = B.createRefToUnowned(loc, semanticValue, storageType);
    unowned = B.createCopyValue(loc, unowned);
    B.emitDestroyValueOperation(loc, semanticValue);
    return unowned;
  }

  // For @unmanaged types, place into an unmanaged box.
  if (storageType.is<UnmanagedStorageType>()) {
    SILValue unmanaged =
      B.createRefToUnmanaged(loc, semanticValue, storageType);
    B.emitDestroyValueOperation(loc, semanticValue);
    return unmanaged;
  }
  
  llvm_unreachable("unexpected storage type that differs from type-of-rvalue");
}