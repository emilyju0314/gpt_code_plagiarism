Value* BuilderImplArith::CreateInverseSqrt(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    return CreateFDiv(ConstantFP::get(pX->getType(), 1.0),
                      CreateUnaryIntrinsic(Intrinsic::sqrt, pX),
                      instName);
}