Value* BuilderImplArith::FDivFast(
    Value* pNumerator,    // [in] Numerator
    Value* pDenominator)  // [in] Denominator
{
    if (pNumerator->getType()->getScalarType()->isFloatTy() == false)
    {
        return CreateFMul(pNumerator, CreateFDiv(ConstantFP::get(pDenominator->getType(), 1.0), pDenominator));
    }

    // We have to scalarize fdiv.fast ourselves.
    return Scalarize(pNumerator,
                     pDenominator,
                     [this](Value* pNumerator, Value* pDenominator) -> Value*
                     {
                        return CreateIntrinsic(Intrinsic::amdgcn_fdiv_fast, {}, { pNumerator, pDenominator });
                     });
}