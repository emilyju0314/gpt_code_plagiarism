Value* BuilderImplArith::CreateACos(
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

    // acos coefficient p0 = 0.08132463
    auto pCoefP0 = GetFpConstant(pX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0x3FB4D1B0E0000000)));
    // acos coefficient p1 = -0.02363318
    auto pCoefP1 = GetFpConstant(pX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0xBF98334BE0000000)));

    Value* pResult = ASinACosCommon(pX, pCoefP0, pCoefP1);

    pResult = CreateFSub(GetPiByTwo(pResult->getType()), pResult);
    pResult = CreateFPTrunc(pResult, pOrigTy);
    pResult->setName(instName);
    return pResult;
}