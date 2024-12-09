Value* BuilderImplArith::CreateATan2(
    Value*        pY,         // [in] Input value Y
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // yox = (|x| == |y|) ? ((x == y) ? 1.0 : -1.0) : y/x
    //
    // p0 = sgn(y) * PI/2
    // p1 = sgn(y) * PI
    // atanyox = atan(yox)
    //
    // if (y != 0.0)
    //     if (x != 0.0)
    //         atan(y, x) = (x < 0.0) ? p1 + atanyox : atanyox
    //     else
    //         atan(y, x) = p0
    // else
    //     atan(y, x) = (x > 0.0) ? 0 : PI

    Constant* pZero = Constant::getNullValue(pY->getType());
    Constant* pOne = ConstantFP::get(pY->getType(), 1.0);
    Constant* pNegOne = ConstantFP::get(pY->getType(), -1.0);

    Value* pAbsX = CreateUnaryIntrinsic(Intrinsic::fabs, pX);
    Value* pAbsY = CreateUnaryIntrinsic(Intrinsic::fabs, pY);
    Value* pSignY = CreateFSign(pY);
    Value* pP0 = CreateFMul(pSignY, GetPiByTwo(pSignY->getType()));
    Value* pP1 = CreateFMul(pSignY, GetPi(pSignY->getType()));

    Value* pAbsXEqualsAbsY = CreateFCmpOEQ(pAbsX, pAbsY);
    // pOneIfEqual to (x == y) ? 1.0 : -1.0
    Value* pOneIfEqual = CreateSelect(CreateFCmpOEQ(pX, pY), pOne, pNegOne);

    Value* pYOverX = FDivFast(pY, pX);

    pYOverX = CreateSelect(pAbsXEqualsAbsY, pOneIfEqual, pYOverX);
    Value* pResult = CreateATan(pYOverX);
    Value* pAddP1 = CreateFAdd(pResult, pP1);
    pResult = CreateSelect(CreateFCmpOLT(pX, pZero), pAddP1, pResult);
    pResult = CreateSelect(CreateFCmpONE(pX, pZero), pResult, pP0);
    Value* pZeroOrPi = CreateSelect(CreateFCmpOGT(pX, pZero), pZero, GetPi(pX->getType()));
    pResult = CreateSelect(CreateFCmpONE(pY, pZero), pResult, pZeroOrPi, instName);
    return pResult;
}