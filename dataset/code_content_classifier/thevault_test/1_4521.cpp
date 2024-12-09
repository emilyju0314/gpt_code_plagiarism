Value* BuilderImplArith::CreateTan(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    Constant* pOne = ConstantFP::get(pX->getType(), 1.0);
    Value* pSin = CreateUnaryIntrinsic(Intrinsic::sin, pX);
    Value* pCos = CreateUnaryIntrinsic(Intrinsic::cos, pX);
    return CreateFMul(pSin, CreateFDiv(pOne, pCos), instName);
}