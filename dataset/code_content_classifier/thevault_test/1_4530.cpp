Value* BuilderImplArith::CreateASinh(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // ln(x + sqrt(x*x + 1))
    //             / ln(x + sqrt(x^2 + 1))      when x >= 0
    //  asinh(x) =
    //             \ -ln((sqrt(x^2 + 1)- x))    when x < 0
    Constant* pOne = ConstantFP::get(pX->getType(), 1.0);
    Constant* pNegOne = ConstantFP::get(pX->getType(), -1.0);

    Value* pSquare = CreateFMul(pX, pX);
    Value* pSqrt = CreateUnaryIntrinsic(Intrinsic::sqrt, CreateFAdd(pSquare, pOne));
    Value* pIsNonNegative = CreateFCmpOGE(pX, Constant::getNullValue(pX->getType()));
    Value* pSign = CreateSelect(pIsNonNegative, pOne, pNegOne);
    Value* pAbs = CreateFMul(pX, pSign);
    Value* pResult = CreateFAdd(pSqrt, pAbs);
    pResult = CreateUnaryIntrinsic(Intrinsic::log2, pResult);
    pResult = CreateFMul(pResult, GetLog2(pX->getType()));
    return CreateFMul(pResult, pSign, instName);
}