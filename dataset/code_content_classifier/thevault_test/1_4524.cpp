Value* BuilderImplArith::ASinACosCommon(
    Value*        pX,         // [in] Input value X
    Constant*     pCoefP0,    // [in] p0 coefficient
    Constant*     pCoefP1)    // [in] p1 coefficient
{
    // asin(x) = sgn(x) * (PI/2 - sqrt(1 - |x|) * (PI/2 + |x| * (PI/4 - 1 + |x| * (p0 + |x| * p1))))
    // acos(x) = PI/2 - the same, but with slightly different coefficients
    Value* pAbsInValue = CreateUnaryIntrinsic(Intrinsic::fabs, pX);
    Value* pResult = CreateFMul(pAbsInValue, pCoefP1);
    pResult = CreateFAdd(pResult, pCoefP0);
    pResult = CreateFMul(pAbsInValue, pResult);
    pResult = CreateFAdd(pResult, GetPiByFourMinusOne(pX->getType()));
    pResult = CreateFMul(pAbsInValue, pResult);
    pResult = CreateFAdd(pResult, GetPiByTwo(pX->getType()));

    Value* pSqrtTerm = CreateUnaryIntrinsic(Intrinsic::sqrt,
                                            CreateFSub(ConstantFP::get(pX->getType(), 1.0), pAbsInValue));
    pResult = CreateFMul(pSqrtTerm, pResult);
    pResult = CreateFSub(GetPiByTwo(pX->getType()), pResult);
    Value* pSign = CreateFSign(pX);
    return CreateFMul(pSign, pResult);
}