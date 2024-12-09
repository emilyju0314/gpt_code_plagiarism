Value* BuilderImplArith::CreateATanh(
    Value*        pX,         // [in] Input value X
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // ln((x + 1)/( 1 - x)) * 0.5f;
    // |x| <1, undefined |x| >= 1
    Constant* pOne = ConstantFP::get(pX->getType(), 1.0);
    Value* pOnePlusX = CreateFAdd(pX, pOne);
    Value* pOneMinusX = CreateFSub(pOne, pX);
    Value* pResult = CreateFMul(pOnePlusX, CreateFDiv(pOne, pOneMinusX));
    pResult = CreateUnaryIntrinsic(Intrinsic::log2, pResult);
    return CreateFMul(pResult, GetHalfLog2(pX->getType()), instName);
}