void LinearScan::getTgtPrefOperands(GenTreeOp* tree, bool& prefOp1, bool& prefOp2)
{
    // If op2 of a binary-op gets marked as contained, then binary-op srcCount will be 1.
    // Even then we would like to set isTgtPref on Op1.
    if (tree->OperIsBinary() && isRMWRegOper(tree))
    {
        GenTree* op1 = tree->gtGetOp1();
        GenTree* op2 = tree->gtGetOp2();

        // If we have a read-modify-write operation, we want to preference op1 to the target,
        // if it is not contained.
        if (!op1->isContained() && !op1->OperIs(GT_LIST))
        {
            prefOp1 = true;
        }

        // Commutative opers like add/mul/and/or/xor could reverse the order of operands if it is safe to do so.
        // In that case we will preference both, to increase the chance of getting a match.
        if (tree->OperIsCommutative() && op2 != nullptr && !op2->isContained())
        {
            prefOp2 = true;
        }
    }
}