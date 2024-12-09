int LinearScan::BuildRMWUses(GenTreeOp* node, regMaskTP candidates)
{
    int       srcCount      = 0;
    GenTree*  op1           = node->gtOp1;
    GenTree*  op2           = node->gtGetOp2IfPresent();
    regMaskTP op1Candidates = candidates;
    regMaskTP op2Candidates = candidates;

#ifdef TARGET_X86
    if (varTypeIsByte(node))
    {
        regMaskTP byteCandidates = (candidates == RBM_NONE) ? allByteRegs() : (candidates & allByteRegs());
        if (!op1->isContained())
        {
            assert(byteCandidates != RBM_NONE);
            op1Candidates = byteCandidates;
        }
        if (node->OperIsCommutative() && !op2->isContained())
        {
            assert(byteCandidates != RBM_NONE);
            op2Candidates = byteCandidates;
        }
    }
#endif // TARGET_X86

    bool prefOp1 = false;
    bool prefOp2 = false;
    getTgtPrefOperands(node, prefOp1, prefOp2);
    assert(!prefOp2 || node->OperIsCommutative());

    // Determine which operand, if any, should be delayRegFree. Normally, this would be op2,
    // but if we have a commutative operator and op1 is a contained memory op, it would be op1.
    // We need to make the delayRegFree operand remain live until the op is complete, by marking
    // the source(s) associated with op2 as "delayFree".
    // Note that if op2 of a binary RMW operator is a memory op, even if the operator
    // is commutative, codegen cannot reverse them.
    // TODO-XArch-CQ: This is not actually the case for all RMW binary operators, but there's
    // more work to be done to correctly reverse the operands if they involve memory
    // operands.  Also, we may need to handle more cases than GT_IND, especially once
    // we've modified the register allocator to not require all nodes to be assigned
    // a register (e.g. a spilled lclVar can often be referenced directly from memory).
    // Note that we may have a null op2, even with 2 sources, if op1 is a base/index memory op.
    GenTree* delayUseOperand = op2;
    if (node->OperIsCommutative())
    {
        if (op1->isContained() && op2 != nullptr)
        {
            delayUseOperand = op1;
        }
        else if (!op2->isContained() || op2->IsCnsIntOrI())
        {
            // If we have a commutative operator and op2 is not a memory op, we don't need
            // to set delayRegFree on either operand because codegen can swap them.
            delayUseOperand = nullptr;
        }
    }
    else if (op1->isContained())
    {
        delayUseOperand = nullptr;
    }
    if (delayUseOperand != nullptr)
    {
        assert(!prefOp1 || delayUseOperand != op1);
        assert(!prefOp2 || delayUseOperand != op2);
    }

    // Build first use
    if (prefOp1)
    {
        assert(!op1->isContained());
        tgtPrefUse = BuildUse(op1, op1Candidates);
        srcCount++;
    }
    else if (delayUseOperand == op1)
    {
        srcCount += BuildDelayFreeUses(op1, op1Candidates);
    }
    else
    {
        srcCount += BuildOperandUses(op1, op1Candidates);
    }
    // Build second use
    if (op2 != nullptr)
    {
        if (prefOp2)
        {
            assert(!op2->isContained());
            tgtPrefUse2 = BuildUse(op2, op2Candidates);
            srcCount++;
        }
        else if (delayUseOperand == op2)
        {
            srcCount += BuildDelayFreeUses(op2, op2Candidates);
        }
        else
        {
            srcCount += BuildOperandUses(op2, op2Candidates);
        }
    }
    return srcCount;
}