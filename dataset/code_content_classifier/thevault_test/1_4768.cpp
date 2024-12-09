int LinearScan::BuildIntrinsic(GenTree* tree)
{
    // Both operand and its result must be of floating point type.
    GenTree* op1 = tree->gtGetOp1();
    assert(varTypeIsFloating(op1));
    assert(op1->TypeGet() == tree->TypeGet());
    RefPosition* internalFloatDef = nullptr;

    switch (tree->AsIntrinsic()->gtIntrinsicId)
    {
        case CORINFO_INTRINSIC_Abs:
            // Abs(float x) = x & 0x7fffffff
            // Abs(double x) = x & 0x7ffffff ffffffff

            // In case of Abs we need an internal register to hold mask.

            // TODO-XArch-CQ: avoid using an internal register for the mask.
            // Andps or andpd both will operate on 128-bit operands.
            // The data section constant to hold the mask is a 64-bit size.
            // Therefore, we need both the operand and mask to be in
            // xmm register. When we add support in emitter to emit 128-bit
            // data constants and instructions that operate on 128-bit
            // memory operands we can avoid the need for an internal register.
            internalFloatDef = buildInternalFloatRegisterDefForNode(tree, internalFloatRegCandidates());
            break;

#ifdef TARGET_X86
        case CORINFO_INTRINSIC_Cos:
        case CORINFO_INTRINSIC_Sin:
            NYI_X86("Math intrinsics Cos and Sin");
            break;
#endif // TARGET_X86

        case CORINFO_INTRINSIC_Sqrt:
        case CORINFO_INTRINSIC_Round:
        case CORINFO_INTRINSIC_Ceiling:
        case CORINFO_INTRINSIC_Floor:
            break;

        default:
            // Right now only Sqrt/Abs are treated as math intrinsics
            noway_assert(!"Unsupported math intrinsic");
            unreached();
            break;
    }
    assert(tree->gtGetOp2IfPresent() == nullptr);
    int srcCount;
    if (op1->isContained())
    {
        srcCount = BuildOperandUses(op1);
    }
    else
    {
        tgtPrefUse = BuildUse(op1);
        srcCount   = 1;
    }
    if (internalFloatDef != nullptr)
    {
        buildInternalRegisterUses();
    }
    BuildDef(tree);
    return srcCount;
}