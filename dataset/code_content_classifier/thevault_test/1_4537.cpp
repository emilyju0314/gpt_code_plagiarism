Value* BuilderImplArith::CreateFMed3(
    Value*        pValue1,    // [in] First value
    Value*        pValue2,    // [in] Second value
    Value*        pValue3,    // [in] Third value
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // For float, and for half on GFX9+, we can use the fmed3 instruction. We need to scalarize this ourselves.
    if (pValue1->getType()->getScalarType()->isFloatTy() || (getContext().GetGfxIpVersion().major >= 9))
    {
        Value* pResult = Scalarize(pValue1,
                                   pValue2,
                                   pValue3,
                                   [this](Value* pValue1, Value* pValue2, Value* pValue3)
                                   {
                                      return CreateIntrinsic(Intrinsic::amdgcn_fmed3,
                                                             pValue1->getType(),
                                                             { pValue1, pValue2, pValue3 });
                                   });
        pResult->setName(instName);
        return pResult;
    }

    // For half on GFX8 or earlier, use a combination of fmin and fmax.
    FastMathFlags fastMathFlags;
    fastMathFlags.setNoNaNs();
    CallInst* pMin1 = CreateMinNum(pValue1, pValue2);
    pMin1->setFastMathFlags(fastMathFlags);
    CallInst* pMax1 = CreateMaxNum(pValue1, pValue2);
    pMax1->setFastMathFlags(fastMathFlags);
    CallInst* pMin2 = CreateMinNum(pMax1, pValue3);
    pMin2->setFastMathFlags(fastMathFlags);
    CallInst* pMax2 = CreateMaxNum(pMin1, pMin2, instName);
    pMax2->setFastMathFlags(fastMathFlags);
    return pMax2;
}