Value* BuilderImplArith::CreateInsertBitField(
    Value*        pBase,                // [in] Base value
    Value*        pInsert,              // [in] Value to insert (same type as base)
    Value*        pOffset,              // Bit number of least-significant end of bitfield
    Value*        pCount,               // Count of bits in bitfield
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

    Value* pBaseXorInsert = CreateXor(CreateShl(pInsert, pOffset), pBase);
    Constant* pOne = ConstantInt::get(pCount->getType(), 1);
    Value* pMask = CreateShl(CreateSub(CreateShl(pOne, pCount), pOne), pOffset);
    Value* pResult = CreateXor(CreateAnd(pBaseXorInsert, pMask), pBase);
    Value* pIsWholeField = CreateICmpEQ(pCount,
                                        ConstantInt::get(pCount->getType(),
                                                         pCount->getType()->getScalarType()->getPrimitiveSizeInBits()));
    return CreateSelect(pIsWholeField, pInsert, pResult, instName);
}