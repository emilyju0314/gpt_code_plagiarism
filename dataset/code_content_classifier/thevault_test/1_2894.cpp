int LinearScan::BuildPutArgStk(GenTreePutArgStk* argNode)
{
    assert(argNode->gtOper == GT_PUTARG_STK);

    GenTree* putArgChild = argNode->gtGetOp1();

    int srcCount = 0;

    // Do we have a TYP_STRUCT argument (or a GT_FIELD_LIST), if so it must be a multireg pass-by-value struct
    if ((putArgChild->TypeGet() == TYP_STRUCT) || (putArgChild->OperGet() == GT_FIELD_LIST))
    {
        // We will use store instructions that each write a register sized value

        if (putArgChild->OperGet() == GT_FIELD_LIST)
        {
            assert(putArgChild->isContained());
            // We consume all of the items in the GT_FIELD_LIST
            for (GenTreeFieldList* current = putArgChild->AsFieldList(); current != nullptr; current = current->Rest())
            {
                BuildUse(current->Current());
                srcCount++;
            }
        }
        else
        {
            // We can use a ldp/stp sequence so we need two internal registers for ARM64; one for ARM.
            buildInternalIntRegisterDefForNode(argNode);
#ifdef _TARGET_ARM64_
            buildInternalIntRegisterDefForNode(argNode);
#endif // _TARGET_ARM64_

            if (putArgChild->OperGet() == GT_OBJ)
            {
                assert(putArgChild->isContained());
                GenTree* objChild = putArgChild->gtGetOp1();
                if (objChild->OperGet() == GT_LCL_VAR_ADDR)
                {
                    // We will generate all of the code for the GT_PUTARG_STK, the GT_OBJ and the GT_LCL_VAR_ADDR
                    // as one contained operation, and there are no source registers.
                    //
                    assert(objChild->isContained());
                }
                else
                {
                    // We will generate all of the code for the GT_PUTARG_STK and its child node
                    // as one contained operation
                    //
                    srcCount = BuildOperandUses(objChild);
                }
            }
            else
            {
                // No source registers.
                putArgChild->OperIs(GT_LCL_VAR);
            }
        }
    }
    else
    {
        assert(!putArgChild->isContained());
        srcCount = BuildOperandUses(putArgChild);
    }
    buildInternalRegisterUses();
    return srcCount;
}