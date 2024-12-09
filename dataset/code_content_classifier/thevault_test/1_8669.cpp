WeakFatPtrLE LgtWeaks::assembleInterfaceWeakRef(
    FunctionState* functionState,
    LLVMBuilderRef builder,
    Reference* sourceType,
    Reference* targetType,
    InterfaceKind* interfaceKindM,
    InterfaceFatPtrLE sourceInterfaceFatPtrLE) {
  assert(sourceType->ownership == Ownership::OWN || sourceType->ownership == Ownership::SHARE);
  // curious, if its a borrow, do we just return sourceRefLE?

  auto controlBlockPtrLE =
      kindStructsSource->getControlBlockPtr(
          FL(), functionState, builder, interfaceKindM, sourceInterfaceFatPtrLE);
  auto lgtiLE = getLgtiFromControlBlockPtr(globalState, builder, kindStructsSource, sourceType,
      controlBlockPtrLE);
  auto currentGenLE = getActualGenFromLGT(functionState, builder, lgtiLE);
  auto headerLE = makeLgtiHeader(globalState, weakRefStructsSource, builder, interfaceKindM, lgtiLE, currentGenLE);

  auto weakRefStructLT =
      weakRefStructsSource->getInterfaceWeakRefStruct(interfaceKindM);

  return fatWeaks_.assembleWeakFatPtr(
      functionState, builder, targetType, weakRefStructLT, headerLE, sourceInterfaceFatPtrLE.refLE);
}