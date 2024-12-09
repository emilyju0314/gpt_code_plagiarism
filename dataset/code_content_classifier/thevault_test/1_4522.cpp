Value* BuilderImplArith::CreateASin(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // Extend half to float.
    Type* pOrigTy = pX->getType();
    Type* pExtTy = pOrigTy;
    if (pExtTy->getScalarType()->isHalfTy())
    {
        pExtTy = GetConditionallyVectorizedTy(getFloatTy(), pExtTy);
        pX = CreateFPExt(pX, pExtTy);
    }

    // asin coefficient p0 = 0.08656672
    auto pCoefP0 = GetFpConstant(pX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0x3FB6293CA0000000)));
    // asin coefficient p1 = -0.03102955
    auto pCoefP1 = GetFpConstant(pX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0xBF9FC635E0000000)));

    Value* pResult = ASinACosCommon(pX, pCoefP0, pCoefP1);

    pResult = CreateFPTrunc(pResult, pOrigTy);
    pResult->setName(instName);
    return pResult;
}