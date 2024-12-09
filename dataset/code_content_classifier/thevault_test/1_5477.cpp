ResultPlanPtr ResultPlanBuilder::buildTopLevelResult(Initialization *init,
                                                     SILLocation loc) {
  // First check if we have a foreign error and/or async convention.
  if (auto foreignAsync = calleeTypeInfo.foreign.async) {
    // Create a result plan that gets the result schema from the completion
    // handler callback's arguments.
    // completion handler.
    return ResultPlanPtr(new ForeignAsyncInitializationPlan(SGF, loc, calleeTypeInfo));
  } else if (auto foreignError = calleeTypeInfo.foreign.error) {
    // Handle the foreign error first.
    //
    // The plan needs to be built using the formal result type after foreign-error
    // adjustment.
    switch (foreignError->getKind()) {
    // These conventions make the formal result type ().
    case ForeignErrorConvention::ZeroResult:
    case ForeignErrorConvention::NonZeroResult:
      assert(calleeTypeInfo.substResultType->isVoid());
      allResults.clear();
      break;

    // These conventions leave the formal result alone.
    case ForeignErrorConvention::ZeroPreservedResult:
    case ForeignErrorConvention::NonNilError:
      break;

    // This convention changes the formal result to the optional object type; we
    // need to make our own make SILResultInfo array.
    case ForeignErrorConvention::NilResult: {
      assert(allResults.size() == 1);
      auto substFnTy = calleeTypeInfo.substFnType;
      CanType objectType = allResults[0]
                               .getReturnValueType(SGF.SGM.M, substFnTy,
                                                   SGF.getTypeExpansionContext())
                               .getOptionalObjectType();
      SILResultInfo optResult = allResults[0].getWithInterfaceType(objectType);
      allResults.clear();
      allResults.push_back(optResult);
      break;
    }
    }

    ResultPlanPtr subPlan = build(init, calleeTypeInfo.origResultType.getValue(),
                                  calleeTypeInfo.substResultType);
    return ResultPlanPtr(new ForeignErrorInitializationPlan(
        SGF, loc, calleeTypeInfo, std::move(subPlan)));
  } else {
    // Otherwise, we can just call build.
    return build(init, calleeTypeInfo.origResultType.getValue(),
                 calleeTypeInfo.substResultType);
  }
}