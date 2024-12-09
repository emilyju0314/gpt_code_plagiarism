Value* BuilderImplArith::CreateCallAmdgcnClass(
    Value*        pValue,     // [in] Input value
    uint32_t      flags,      // Flags for what class(es) to check for
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    Value* pResult = Scalarize(pValue,
                               [this, flags](Value* pValue)
                               {
                                  return CreateIntrinsic(Intrinsic::amdgcn_class,
                                                         pValue->getType(),
                                                         { pValue, getInt32(flags) });
                               });
    pResult->setName(instName);
    return pResult;
}