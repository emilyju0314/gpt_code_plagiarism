Value* BuilderImplArith::CreatePower(
    Value*        pX,         // [in] Input value X
    Value*        pY,         // [in] Input value Y
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // llvm.pow only works with (vector of) float.
    if (pX->getType()->getScalarType()->isFloatTy())
    {
        return CreateBinaryIntrinsic(Intrinsic::pow, pX, pY, nullptr, instName);
    }

    // pow(x, y) = exp2(y * log2(x))
    Value *pLog = CreateUnaryIntrinsic(Intrinsic::log2, pX);
    return CreateUnaryIntrinsic(Intrinsic::exp2, CreateFMul(pY, pLog), nullptr, instName);
}