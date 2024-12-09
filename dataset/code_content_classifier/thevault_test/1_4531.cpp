Value* BuilderImplArith::CreateACosh(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // ln(x + sqrt(x*x - 1))
    // x should >= 1, undefined < 1
    Constant* pOne = ConstantFP::get(pX->getType(), 1.0);

    Value* pSquare = CreateFMul(pX, pX);
    Value* pSqrt = CreateUnaryIntrinsic(Intrinsic::sqrt, CreateFSub(pSquare, pOne));
    Value* pResult = CreateFAdd(pX, pSqrt);
    pResult = CreateUnaryIntrinsic(Intrinsic::log2, pResult);
    return CreateFMul(pResult, GetLog2(pX->getType()));
}