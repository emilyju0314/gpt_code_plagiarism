LValue SILGenFunction::emitPropertyLValue(SILLocation loc, ManagedValue base,
                                          CanType baseFormalType,
                                          VarDecl *ivar,
                                          LValueOptions options,
                                          AccessKind accessKind,
                                          AccessSemantics semantics) {
  SILGenLValue sgl(*this);
  LValue lv;

  auto baseType = base.getType().getSwiftRValueType();
  auto subMap = baseType->getContextSubstitutionMap(
      SGM.M.getSwiftModule(), ivar->getDeclContext());

  SmallVector<Substitution, 4> subs;
  if (auto *genericSig = ivar->getDeclContext()->getGenericSignatureOfContext())
    genericSig->getSubstitutions(subMap, subs);

  LValueTypeData baseTypeData = getValueTypeData(baseFormalType,
                                                 base.getValue());

  // Refer to 'self' as the base of the lvalue.
  lv.add<ValueComponent>(base, None, baseTypeData,
                         /*isRValue=*/!base.isLValue());

  auto substFormalType = ivar->getInterfaceType().subst(subMap)
    ->getCanonicalType();

  AccessStrategy strategy =
    ivar->getAccessStrategy(semantics, accessKind);


  // Use the property accessors if the variable has accessors and this
  // isn't a direct access to underlying storage.
  if (strategy == AccessStrategy::DirectToAccessor ||
      strategy == AccessStrategy::DispatchToAccessor) {
    auto typeData = getLogicalStorageTypeData(SGM, substFormalType);
    lv.add<GetterSetterComponent>(ivar, /*super*/ false,
                                  strategy == AccessStrategy::DirectToAccessor,
                                  subs, baseFormalType, typeData);
    return lv;
  }

  assert(strategy == AccessStrategy::Addressor ||
         strategy == AccessStrategy::Storage);

  // Find the substituted storage type.
  SILType varStorageType =
    SGM.Types.getSubstitutedStorageType(ivar, substFormalType);

  auto typeData = getPhysicalStorageTypeData(SGM, ivar, substFormalType);

  if (strategy == AccessStrategy::Addressor) {
    lv.add<AddressorComponent>(ivar, /*super*/ false, /*direct*/ true,
                               subs, baseFormalType, typeData, varStorageType);
  } else if (baseFormalType->hasReferenceSemantics()) {
    lv.add<RefElementComponent>(ivar, options, varStorageType, typeData);
  } else {
    lv.add<StructElementComponent>(ivar, varStorageType, typeData);
  }

  if (varStorageType.is<ReferenceStorageType>()) {
    auto formalRValueType =
      ivar->getDeclContext()->mapTypeIntoContext(ivar->getInterfaceType())
          ->getReferenceStorageReferent()
          ->getCanonicalType();
    auto typeData =
      getPhysicalStorageTypeData(SGM, ivar, formalRValueType);
    lv.add<OwnershipComponent>(typeData);
  }

  return lv;
}