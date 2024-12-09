Value* BuilderImplArith::CreateLog(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    Value* pLog = CreateUnaryIntrinsic(Intrinsic::log2, pX);
    return CreateFMul(pLog, GetLog2(pX->getType()), instName);
}