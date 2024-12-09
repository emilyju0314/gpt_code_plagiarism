Value* BuilderImplArith::CreateCubeFaceCoord(
    Value*        pCoord,     // [in] Input coordinate <3 x float>
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    Value* pCoordX = CreateExtractElement(pCoord, uint64_t(0));
    Value* pCoordY = CreateExtractElement(pCoord, 1);
    Value* pCoordZ = CreateExtractElement(pCoord, 2);
    Value* pCubeMa = CreateIntrinsic(Intrinsic::amdgcn_cubema, {}, { pCoordX, pCoordY, pCoordZ }, nullptr);
    Value* pRecipMa = CreateFDiv(ConstantFP::get(getFloatTy(), 1.0), pCubeMa);
    Value* pCubeSc = CreateIntrinsic(Intrinsic::amdgcn_cubesc, {}, { pCoordX, pCoordY, pCoordZ }, nullptr);
    Value* pScDivMa = CreateFMul(pRecipMa, pCubeSc);
    Value* pResultX = CreateFAdd(pScDivMa, ConstantFP::get(getFloatTy(), 0.5));
    Value* pCubeTc = CreateIntrinsic(Intrinsic::amdgcn_cubetc, {}, { pCoordX, pCoordY, pCoordZ }, nullptr);
    Value* pTcDivMa = CreateFMul(pRecipMa, pCubeTc);
    Value* pResultY = CreateFAdd(pTcDivMa, ConstantFP::get(getFloatTy(), 0.5));
    Value* pResult = CreateInsertElement(UndefValue::get(VectorType::get(getFloatTy(), 2)), pResultX, uint64_t(0));
    pResult = CreateInsertElement(pResult, pResultY, 1, instName);
    return pResult;
}