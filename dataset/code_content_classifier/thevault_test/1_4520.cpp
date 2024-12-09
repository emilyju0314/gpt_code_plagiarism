Value* BuilderImplArith::CreateSMod(
    Value*        pDividend,  // [in] Dividend value
    Value*        pDivisor,   // [in] Divisor value
    const Twine&  instName)   // [in] Name to give instruction(s)
{
#if LLPC_BUILD_GFX10
    if (pDivisor->getType()->getScalarType()->isIntegerTy(32) &&
        (getContext().GetGpuWorkarounds()->gfx10.disableI32ModToI16Mod))
    {

        // NOTE: On some hardware, when the divisor is a literal value and less than 0xFFFF, i32 mod will be
        // optimized to i16 mod. There is an existing issue in the backend which makes i16 mod not work.
        // This is the workaround to this issue.
        // TODO: Check if this is still needed and what the backend problem is.
        if (auto pDivisorConst = dyn_cast<ConstantInt>(pDivisor))
        {
            if (pDivisorConst->getZExtValue() <= 0xFFFF)
            {
                // Get a non-constant 0 value. (We know the top 17 bits of the 64-bit PC is always zero.)
                Value* pPc = CreateIntrinsic(Intrinsic::amdgcn_s_getpc, {}, {});
                Value* pPcHi = CreateExtractElement(CreateBitCast(pPc, VectorType::get(getInt32Ty(), 2)), 1);
                Value* pNonConstantZero = CreateLShr(pPcHi, getInt32(15));
                if (auto pVecTy = dyn_cast<VectorType>(pDivisor->getType()))
                {
                    pNonConstantZero = CreateVectorSplat(pVecTy->getNumElements(), pNonConstantZero);
                }
                // Add the non-constant 0 to the denominator to disable the optimization.
                pDivisor = CreateAdd(pDivisor, pNonConstantZero);
            }
        }
    }
#endif

    Value* pSrem = CreateSRem(pDividend, pDivisor);
    Value* pDivisorPlusSrem = CreateAdd(pDivisor, pSrem);
    Value* pIsDifferentSign = CreateICmpSLT(CreateXor(pDividend, pDivisor),
                                            Constant::getNullValue(pDividend->getType()));
    Value* pRemainderNotZero = CreateICmpNE(pSrem, Constant::getNullValue(pSrem->getType()));
    Value* pResultNeedsAddDivisor = CreateAnd(pIsDifferentSign, pRemainderNotZero);
    return CreateSelect(pResultNeedsAddDivisor, pDivisorPlusSrem, pSrem, instName);
}