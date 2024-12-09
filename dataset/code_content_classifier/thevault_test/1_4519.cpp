Value* BuilderImplArith::CreateQuantizeToFp16(
    Value*        pValue,     // [in] Input value (float or float vector)
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    LLPC_ASSERT(pValue->getType()->getScalarType()->isFloatTy());

    Constant* pZero = Constant::getNullValue(pValue->getType());
    // 2^-15 (normalized float16 minimum)
    Constant* pMinNormalizedHalf = ConstantFP::get(pValue->getType(), 1.0 / 32768.0);

    Value* pTrunc = CreateFPTrunc(pValue, GetConditionallyVectorizedTy(getHalfTy(), pValue->getType()));
    Value* pExt = CreateFPExt(pTrunc, pValue->getType());
    Value* pAbs = CreateIntrinsic(Intrinsic::fabs, pExt->getType(), pExt);
    Value* pIsLessThanMin = CreateFCmpOLT(pAbs, pMinNormalizedHalf);
    Value* pIsNotZero = CreateFCmpONE(pAbs, pZero);
    Value* pIsDenorm = CreateAnd(pIsLessThanMin, pIsNotZero);
    Value* pResult = CreateSelect(pIsDenorm, pZero, pExt);

    // Check NaN.
    Value* pIsNan = CreateIsNaN(pValue);
    return CreateSelect(pIsNan, pValue, pResult, instName);
}