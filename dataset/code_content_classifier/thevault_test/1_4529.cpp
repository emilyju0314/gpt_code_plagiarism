Value* BuilderImplArith::CreateTanh(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // sinh(x) / cosh(x)
    // (e^x - e^(-x))/(e^x + e^(-x))
    // 1/log(2) = 1.442695
    // e^x = 2^(x*(1/log(2))) = 2^(x*1.442695))
    Value* pDivLog2 = CreateFMul(pX, GetRecipLog2(pX->getType()));
    Value* pNegDivLog2 = CreateFSub(ConstantFP::get(pX->getType(), 0.0), pDivLog2);
    Value* pExp = CreateUnaryIntrinsic(Intrinsic::exp2, pDivLog2);
    Value* pExpNeg = CreateUnaryIntrinsic(Intrinsic::exp2, pNegDivLog2);
    Value* pDoubleSinh = CreateFSub(pExp, pExpNeg);
    Value* pDoubleCosh = CreateFAdd(pExp, pExpNeg);
    Value* pResult = FDivFast(pDoubleSinh, pDoubleCosh);
    pResult->setName(instName);
    return pResult;
}