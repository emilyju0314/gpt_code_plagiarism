Value* BuilderImplArith::CreateATan(
    Value*        pYOverX,    // [in] Input value Y/X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // atan(x) = x - x^3 / 3 + x^5 / 5 - x^7 / 7 + x^9 / 9 - x^11 / 11, |x| <= 1.0
    // x = min(1.0, x) / max(1.0, x), make |x| <= 1.0
    Constant* pZero = Constant::getNullValue(pYOverX->getType());
    Constant* pOne = ConstantFP::get(pYOverX->getType(), 1.0);

    Value* pAbsX = CreateUnaryIntrinsic(Intrinsic::fabs, pYOverX);
    Value* pMax = CreateBinaryIntrinsic(Intrinsic::maxnum, pAbsX, pOne);
    Value* pMin = CreateBinaryIntrinsic(Intrinsic::minnum, pAbsX, pOne);
    Value* pBoundedX = CreateFMul(pMin, CreateFDiv(pOne, pMax));
    Value* pSquare = CreateFMul(pBoundedX, pBoundedX);
    Value* pCube = CreateFMul(pSquare, pBoundedX);
    Value* pPow5 = CreateFMul(pCube, pSquare);
    Value* pPow7 = CreateFMul(pPow5, pSquare);
    Value* pPow9 = CreateFMul(pPow7, pSquare);
    Value* pPow11 = CreateFMul(pPow9, pSquare);

    // coef1 = 0.99997932
    auto pCoef1 = GetFpConstant(pYOverX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0x3FEFFFD4A0000000)));
    // coef3 = -0.33267564
    auto pCoef3 = GetFpConstant(pYOverX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0xBFD54A8EC0000000)));
    // coef5 = 0.19389249
    auto pCoef5 = GetFpConstant(pYOverX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0x3FC8D17820000000)));
    // coef7 = -0.11735032
    auto pCoef7 = GetFpConstant(pYOverX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0xBFBE0AABA0000000)));
    // coef9 = 0.05368138
    auto pCoef9 = GetFpConstant(pYOverX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0x3FAB7C2020000000)));
    // coef11 = -0.01213232
    auto pCoef11 = GetFpConstant(pYOverX->getType(), APFloat(APFloat::IEEEdouble(), APInt(64, 0xBF88D8D4A0000000)));

    Value* pTerm1 = CreateFMul(pBoundedX, pCoef1);
    Value* pTerm3 = CreateFMul(pCube, pCoef3);
    Value* pTerm5 = CreateFMul(pPow5, pCoef5);
    Value* pTerm7 = CreateFMul(pPow7, pCoef7);
    Value* pTerm9 = CreateFMul(pPow9, pCoef9);
    Value* pTerm11 = CreateFMul(pPow11, pCoef11);

    Value* pResult = CreateFAdd(pTerm1, pTerm3);
    pResult = CreateFAdd(pResult, pTerm5);
    pResult = CreateFAdd(pResult, pTerm7);
    pResult = CreateFAdd(pResult, pTerm9);
    Value* pPartialResult = CreateFAdd(pResult, pTerm11);
    pResult = CreateFMul(pPartialResult, ConstantFP::get(pYOverX->getType(), -2.0));
    pResult = CreateFAdd(pResult, GetPiByTwo(pYOverX->getType()));
    Value* pOutsideBound = CreateSelect(CreateFCmpOGT(pAbsX, pOne), pOne, pZero);
    pResult = CreateFMul(pOutsideBound, pResult);
    pResult = CreateFAdd(pPartialResult, pResult);
    return CreateFMul(pResult, CreateFSign(pYOverX));
}