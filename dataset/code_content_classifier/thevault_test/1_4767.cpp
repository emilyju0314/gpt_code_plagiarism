int LinearScan::BuildBlockStore(GenTreeBlk* blkNode)
{
    GenTree* dstAddr = blkNode->Addr();
    GenTree* src     = blkNode->Data();
    unsigned size    = blkNode->Size();

    GenTree* srcAddrOrFill = nullptr;

    regMaskTP dstAddrRegMask = RBM_NONE;
    regMaskTP srcRegMask     = RBM_NONE;
    regMaskTP sizeRegMask    = RBM_NONE;

    if (blkNode->OperIsInitBlkOp())
    {
        if (src->OperIs(GT_INIT_VAL))
        {
            assert(src->isContained());
            src = src->AsUnOp()->gtGetOp1();
        }

        srcAddrOrFill = src;

        switch (blkNode->gtBlkOpKind)
        {
            case GenTreeBlk::BlkOpKindUnroll:
                if (size >= XMM_REGSIZE_BYTES)
                {
                    buildInternalFloatRegisterDefForNode(blkNode, internalFloatRegCandidates());
                    SetContainsAVXFlags();
                }

#ifdef TARGET_X86
                if ((size & 1) != 0)
                {
                    // We'll need to store a byte so a byte register is needed on x86.
                    srcRegMask = allByteRegs();
                }
#endif
                break;

            case GenTreeBlk::BlkOpKindRepInstr:
                dstAddrRegMask = RBM_RDI;
                srcRegMask     = RBM_RAX;
                sizeRegMask    = RBM_RCX;
                break;

#ifdef TARGET_AMD64
            case GenTreeBlk::BlkOpKindHelper:
                dstAddrRegMask = RBM_ARG_0;
                srcRegMask     = RBM_ARG_1;
                sizeRegMask    = RBM_ARG_2;
                break;
#endif

            default:
                unreached();
        }
    }
    else
    {
        if (src->OperIs(GT_IND))
        {
            assert(src->isContained());
            srcAddrOrFill = src->AsIndir()->Addr();
        }

        if (blkNode->OperIs(GT_STORE_OBJ))
        {
            if (blkNode->gtBlkOpKind == GenTreeBlk::BlkOpKindRepInstr)
            {
                // We need the size of the contiguous Non-GC-region to be in RCX to call rep movsq.
                sizeRegMask = RBM_RCX;
            }

            // The srcAddr must be in a register.  If it was under a GT_IND, we need to subsume all of its
            // sources.
            dstAddrRegMask = RBM_RDI;
            srcRegMask     = RBM_RSI;
        }
        else
        {
            switch (blkNode->gtBlkOpKind)
            {
                case GenTreeBlk::BlkOpKindUnroll:
                    if ((size % XMM_REGSIZE_BYTES) != 0)
                    {
                        regMaskTP regMask = allRegs(TYP_INT);
#ifdef TARGET_X86
                        if ((size & 1) != 0)
                        {
                            // We'll need to store a byte so a byte register is needed on x86.
                            regMask = allByteRegs();
                        }
#endif
                        buildInternalIntRegisterDefForNode(blkNode, regMask);
                    }

                    if (size >= XMM_REGSIZE_BYTES)
                    {
                        buildInternalFloatRegisterDefForNode(blkNode, internalFloatRegCandidates());
                        SetContainsAVXFlags();
                    }
                    break;

                case GenTreeBlk::BlkOpKindRepInstr:
                    dstAddrRegMask = RBM_RDI;
                    srcRegMask     = RBM_RSI;
                    sizeRegMask    = RBM_RCX;
                    break;

#ifdef TARGET_AMD64
                case GenTreeBlk::BlkOpKindHelper:
                    dstAddrRegMask = RBM_ARG_0;
                    srcRegMask     = RBM_ARG_1;
                    sizeRegMask    = RBM_ARG_2;
                    break;
#endif

                default:
                    unreached();
            }
        }

        if ((srcAddrOrFill == nullptr) && (srcRegMask != RBM_NONE))
        {
            // This is a local source; we'll use a temp register for its address.
            assert(src->isContained() && src->OperIs(GT_LCL_VAR, GT_LCL_FLD));
            buildInternalIntRegisterDefForNode(blkNode, srcRegMask);
        }
    }

    if (!blkNode->OperIs(GT_STORE_DYN_BLK) && (sizeRegMask != RBM_NONE))
    {
        // Reserve a temp register for the block size argument.
        buildInternalIntRegisterDefForNode(blkNode, sizeRegMask);
    }

    int useCount = 0;

    if (!dstAddr->isContained())
    {
        useCount++;
        BuildUse(dstAddr, dstAddrRegMask);
    }
    else if (dstAddr->OperIsAddrMode())
    {
        useCount += BuildAddrUses(dstAddr);
    }

    if (srcAddrOrFill != nullptr)
    {
        if (!srcAddrOrFill->isContained())
        {
            useCount++;
            BuildUse(srcAddrOrFill, srcRegMask);
        }
        else if (srcAddrOrFill->OperIsAddrMode())
        {
            useCount += BuildAddrUses(srcAddrOrFill);
        }
    }

    if (blkNode->OperIs(GT_STORE_DYN_BLK))
    {
        useCount++;
        BuildUse(blkNode->AsDynBlk()->gtDynamicSize, sizeRegMask);
    }

    buildInternalRegisterUses();
    regMaskTP killMask = getKillSetForBlockStore(blkNode);
    BuildDefsWithKills(blkNode, 0, RBM_NONE, killMask);
    return useCount;
}