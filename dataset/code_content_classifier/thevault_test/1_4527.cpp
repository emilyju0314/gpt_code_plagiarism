Value* BuilderImplArith::CreateSinh(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // (e^x - e^(-x)) / 2.0
    // e^x = 2^(x * 1.442695)
    // 1/log(2) = 1.442695
    // e^x = 2^(x*(1/log(2))) = 2^(x*1.442695))
    Constant* pZero = Constant::getNullValue(pX->getType());
    Constant* pHalf = ConstantFP::get(pX->getType(), 0.5);
    Value* pDivLog2 = CreateFMul(pX, GetRecipLog2(pX->getType()));
    Value* pNegDivLog2 = CreateFSub(pZero, pDivLog2);
    Value* pExp = CreateUnaryIntrinsic(Intrinsic::exp2, pDivLog2);
    Value* pExpNeg = CreateUnaryIntrinsic(Intrinsic::exp2, pNegDivLog2);
    Value* pResult = CreateFSub(pExp, pExpNeg);
    return CreateFMul(pResult, pHalf, instName);
}