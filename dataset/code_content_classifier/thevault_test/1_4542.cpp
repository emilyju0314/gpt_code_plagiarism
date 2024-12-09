Value* BuilderImplArith::CreateExtractBitField(
    Value*        pBase,                // [in] Base value
    Value*        pOffset,              // Bit number of least-significant end of bitfield
    Value*        pCount,               // Count of bits in bitfield
    bool          isSigned,             // True for a signed int bitfield extract, false for unsigned
    const Twine&  instName)             // [in] Name to give instruction(s)
{
    // Make pOffset and pCount vectors of the right integer type if necessary.
    if (auto pVecTy = dyn_cast<VectorType>(pBase->getType()))
    {
        if (isa<VectorType>(pOffset->getType()) == false)
        {
            pOffset = CreateVectorSplat(pVecTy->getNumElements(), pOffset);
        }
        if (isa<VectorType>(pCount->getType()) == false)
        {
            pCount = CreateVectorSplat(pVecTy->getNumElements(), pCount);
        }
    }
    pOffset = CreateZExtOrTrunc(pOffset, pBase->getType());
    pCount = CreateZExtOrTrunc(pCount, pBase->getType());

    // For i32, we can use the amdgcn intrinsic and hence the instruction.
    if (pBase->getType()->getScalarType()->isIntegerTy(32))
    {
        Value* pIsWholeField = CreateICmpEQ(
                                    pCount,
                                    ConstantInt::get(pCount->getType(),
                                                     pCount->getType()->getScalarType()->getPrimitiveSizeInBits()));
        Value* pResult = Scalarize(pBase,
                                   pOffset,
                                   pCount,
                                   [this, isSigned](Value* pBase, Value* pOffset, Value* pCount)
                                   {
                                      return CreateIntrinsic(isSigned ? Intrinsic::amdgcn_sbfe : Intrinsic::amdgcn_ubfe,
                                                             pBase->getType(),
                                                             { pBase, pOffset, pCount });
                                   });
        pResult = CreateSelect(pIsWholeField, pBase, pResult);
        Value* pIsEmptyField = CreateICmpEQ(pCount, Constant::getNullValue(pCount->getType()));
        return CreateSelect(pIsEmptyField, Constant::getNullValue(pCount->getType()), pResult, instName);
    }

    // For other types, extract manually.
    Value* pShiftDown = CreateSub(ConstantInt::get(pBase->getType(),
                                                   pBase->getType()->getScalarType()->getPrimitiveSizeInBits()),
                                  pCount);
    Value* pShiftUp = CreateSub(pShiftDown, pOffset);
    Value* pResult = CreateShl(pBase, pShiftUp);
    if (isSigned)
    {
        pResult = CreateAShr(pResult, pShiftDown);
    }
    else
    {
        pResult = CreateLShr(pResult, pShiftDown);
    }
    Value* pIsZeroCount = CreateICmpEQ(pCount, Constant::getNullValue(pCount->getType()));
    return CreateSelect(pIsZeroCount, pCount, pResult, instName);
}