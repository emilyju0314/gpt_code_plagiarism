int LinearScan::BuildCast(GenTreeCast* cast)
{
    GenTree* src = cast->gtGetOp1();

    const var_types srcType  = genActualType(src->TypeGet());
    const var_types castType = cast->gtCastType;

#ifdef _TARGET_ARM_
    assert(!varTypeIsLong(srcType) || (src->OperIs(GT_LONG) && src->isContained()));

    // Floating point to integer casts requires a temporary register.
    if (varTypeIsFloating(srcType) && !varTypeIsFloating(castType))
    {
        buildInternalFloatRegisterDefForNode(cast, RBM_ALLFLOAT);
        setInternalRegsDelayFree = true;
    }
#else
    // Overflow checking cast from TYP_LONG to TYP_INT requires a temporary register to
    // store the min and max immediate values that cannot be encoded in the CMP instruction.
    if (cast->gtOverflow() && varTypeIsLong(srcType) && !cast->IsUnsigned() && (castType == TYP_INT))
    {
        buildInternalIntRegisterDefForNode(cast);
    }
#endif

    int srcCount = BuildOperandUses(src);
    buildInternalRegisterUses();
    BuildDef(cast);
    return srcCount;
}