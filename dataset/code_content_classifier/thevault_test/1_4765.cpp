bool LinearScan::isRMWRegOper(GenTree* tree)
{
    // TODO-XArch-CQ: Make this more accurate.
    // For now, We assume that most binary operators are of the RMW form.
    assert(tree->OperIsBinary());

    if (tree->OperIsCompare() || tree->OperIs(GT_CMP) || tree->OperIs(GT_BT))
    {
        return false;
    }

    switch (tree->OperGet())
    {
        // These Opers either support a three op form (i.e. GT_LEA), or do not read/write their first operand
        case GT_LEA:
        case GT_STOREIND:
        case GT_ARR_INDEX:
        case GT_STORE_BLK:
        case GT_STORE_OBJ:
        case GT_SWITCH_TABLE:
        case GT_LOCKADD:
#ifdef TARGET_X86
        case GT_LONG:
#endif
            return false;

        case GT_ADD:
        case GT_SUB:
        case GT_DIV:
        {
            return !varTypeIsFloating(tree->TypeGet()) || !compiler->canUseVexEncoding();
        }

        // x86/x64 does support a three op multiply when op2|op1 is a contained immediate
        case GT_MUL:
        {
            if (varTypeIsFloating(tree->TypeGet()))
            {
                return !compiler->canUseVexEncoding();
            }
            return (!tree->gtGetOp2()->isContainedIntOrIImmed() && !tree->gtGetOp1()->isContainedIntOrIImmed());
        }

#ifdef FEATURE_HW_INTRINSICS
        case GT_HWINTRINSIC:
            return tree->isRMWHWIntrinsic(compiler);
#endif // FEATURE_HW_INTRINSICS

        default:
            return true;
    }
}