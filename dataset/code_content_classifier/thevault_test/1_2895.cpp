int LinearScan::BuildBlockStore(GenTreeBlk* blkNode)
{
    GenTree* dstAddr  = blkNode->Addr();
    unsigned size     = blkNode->gtBlkSize;
    GenTree* source   = blkNode->Data();
    int      srcCount = 0;

    GenTree* srcAddrOrFill = nullptr;
    bool     isInitBlk     = blkNode->OperIsInitBlkOp();

    regMaskTP dstAddrRegMask        = RBM_NONE;
    regMaskTP sourceRegMask         = RBM_NONE;
    regMaskTP blkSizeRegMask        = RBM_NONE;
    regMaskTP internalIntCandidates = RBM_NONE;

    if (isInitBlk)
    {
        GenTree* initVal = source;
        if (initVal->OperIsInitVal())
        {
            assert(initVal->isContained());
            initVal = initVal->gtGetOp1();
        }
        srcAddrOrFill = initVal;

        if (blkNode->gtBlkOpKind == GenTreeBlk::BlkOpKindUnroll)
        {
            // TODO-ARM-CQ: Currently we generate a helper call for every
            // initblk we encounter.  Later on we should implement loop unrolling
            // code sequences to improve CQ.
            // For reference see the code in lsraxarch.cpp.
            NYI_ARM("initblk loop unrolling is currently not implemented.");
        }
        else
        {
            assert(blkNode->gtBlkOpKind == GenTreeBlk::BlkOpKindHelper);
            assert(!initVal->isContained());
            // The helper follows the regular ABI.
            dstAddrRegMask = RBM_ARG_0;
            sourceRegMask  = RBM_ARG_1;
            blkSizeRegMask = RBM_ARG_2;
        }
    }
    else
    {
        // CopyObj or CopyBlk
        // Sources are src and dest and size if not constant.
        if (source->gtOper == GT_IND)
        {
            assert(source->isContained());
            srcAddrOrFill = source->gtGetOp1();
            assert(!srcAddrOrFill->isContained());
        }
        if (blkNode->OperGet() == GT_STORE_OBJ)
        {
            // CopyObj
            // We don't need to materialize the struct size but we still need
            // a temporary register to perform the sequence of loads and stores.
            // We can't use the special Write Barrier registers, so exclude them from the mask
            internalIntCandidates = allRegs(TYP_INT) & ~(RBM_WRITE_BARRIER_DST_BYREF | RBM_WRITE_BARRIER_SRC_BYREF);
            buildInternalIntRegisterDefForNode(blkNode, internalIntCandidates);

            if (size >= 2 * REGSIZE_BYTES)
            {
                // We will use ldp/stp to reduce code size and improve performance
                // so we need to reserve an extra internal register
                buildInternalIntRegisterDefForNode(blkNode, internalIntCandidates);
            }

            // If we have a dest address we want it in RBM_WRITE_BARRIER_DST_BYREF.
            dstAddrRegMask = RBM_WRITE_BARRIER_DST_BYREF;

            // If we have a source address we want it in REG_WRITE_BARRIER_SRC_BYREF.
            // Otherwise, if it is a local, codegen will put its address in REG_WRITE_BARRIER_SRC_BYREF,
            // which is killed by a StoreObj (and thus needn't be reserved).
            if (srcAddrOrFill != nullptr)
            {
                sourceRegMask = RBM_WRITE_BARRIER_SRC_BYREF;
            }
        }
        else
        {
            // CopyBlk
            if (blkNode->gtBlkOpKind == GenTreeBlk::BlkOpKindUnroll)
            {
                // In case of a CpBlk with a constant size and less than CPBLK_UNROLL_LIMIT size
                // we should unroll the loop to improve CQ.
                // For reference see the code in lsraxarch.cpp.

                buildInternalIntRegisterDefForNode(blkNode);

#ifdef _TARGET_ARM64_
                if (size >= 2 * REGSIZE_BYTES)
                {
                    // We will use ldp/stp to reduce code size and improve performance
                    // so we need to reserve an extra internal register
                    buildInternalIntRegisterDefForNode(blkNode);
                }
#endif // _TARGET_ARM64_
            }
            else
            {
                assert(blkNode->gtBlkOpKind == GenTreeBlk::BlkOpKindHelper);
                dstAddrRegMask = RBM_ARG_0;
                // The srcAddr goes in arg1.
                if (srcAddrOrFill != nullptr)
                {
                    sourceRegMask = RBM_ARG_1;
                }
                blkSizeRegMask = RBM_ARG_2;
            }
        }
    }

    if (!blkNode->OperIs(GT_STORE_DYN_BLK) && (blkSizeRegMask != RBM_NONE))
    {
        // Reserve a temp register for the block size argument.
        buildInternalIntRegisterDefForNode(blkNode, blkSizeRegMask);
    }

    if (!dstAddr->isContained() && !blkNode->IsReverseOp())
    {
        srcCount++;
        BuildUse(dstAddr, dstAddrRegMask);
    }
    if ((srcAddrOrFill != nullptr) && !srcAddrOrFill->isContained())
    {
        srcCount++;
        BuildUse(srcAddrOrFill, sourceRegMask);
    }
    if (!dstAddr->isContained() && blkNode->IsReverseOp())
    {
        srcCount++;
        BuildUse(dstAddr, dstAddrRegMask);
    }

    if (blkNode->OperIs(GT_STORE_DYN_BLK))
    {
        // The block size argument is a third argument to GT_STORE_DYN_BLK
        srcCount++;
        GenTree* blockSize = blkNode->AsDynBlk()->gtDynamicSize;
        BuildUse(blockSize, blkSizeRegMask);
    }

    buildInternalRegisterUses();
    regMaskTP killMask = getKillSetForBlockStore(blkNode);
    BuildDefsWithKills(blkNode, 0, RBM_NONE, killMask);
    return srcCount;
}