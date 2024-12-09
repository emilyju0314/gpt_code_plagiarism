Value* BuilderImplArith::CreateIsNaN(
    Value*        pX,         // [in] Input value
    const Twine&  instName)   // [in] Name to give instruction(s)
{
    // 0x001: signaling NaN, 0x002: quiet NaN
    return CreateCallAmdgcnClass(pX, 0x003, instName);
}