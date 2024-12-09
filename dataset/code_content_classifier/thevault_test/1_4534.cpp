Value* BuilderImplArith::CreateExp(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    return CreateUnaryIntrinsic(Intrinsic::exp2,
                                CreateFMul(pX, GetRecipLog2(pX->getType())),
                                nullptr,
                                instName);
}