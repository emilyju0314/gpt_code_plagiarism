Value* BuilderImplArith::CreateCubeFaceIndex(
    Value*        pCoord,     // [in] Input coordinate <3 x float>
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    Value* pCoordX = CreateExtractElement(pCoord, uint64_t(0));
    Value* pCoordY = CreateExtractElement(pCoord, 1);
    Value* pCoordZ = CreateExtractElement(pCoord, 2);
    return CreateIntrinsic(Intrinsic::amdgcn_cubeid, {}, { pCoordX, pCoordY, pCoordZ }, nullptr, instName);
}