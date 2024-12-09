int LinearScan::BuildBlockStore(GenTreeBlk* blkNode)
{
    GenTree* dstAddr  = blkNode->Addr();
    unsigned size     = blkNode->gtBlkSize;
    GenTree* source   = blkNode->Data();
    int      srcCount = 0;

    GenTree* srcAddrOrFill = nullptr;
    bool     isInitBlk     = blkNode->OperIsInitBlkOp();

    regMaskTP dstAddrRegMask = RBM_NONE;
    regMaskTP sourceRegMask  = RBM_NONE;
    regMaskTP blkSizeRegMask = RBM_NONE;

    if (isInitBlk)
    {
        GenTree* initVal = source;
        if (initVal->OperIsInitVal())
        {
            assert(initVal->isContained());
            initVal = initVal->gtGetOp1();
        }
        srcAddrOrFill = initVal;

        switch (blkNode->gtBlkOpKind)
        {
            case GenTreeBlk::BlkOpKindUnroll:
                assert(initVal->IsCnsIntOrI());
                if (size >= XMM_REGSIZE_BYTES)
                {
                    // Reserve an XMM register to fill it with a pack of 16 init value constants.
                    buildInternalFloatRegisterDefForNode(blkNode, internalFloatRegCandidates());
                    // use XMM register to fill with constants, it's AVX instruction and set the flag
                    SetContainsAVXFlags();
                }
#ifdef _TARGET_X86_
                if ((size & 1) != 0)
                {
                    // On x86, you can't address the lower byte of ESI, EDI, ESP, or EBP when doing
                    // a "mov byte ptr [dest], val". If the fill size is odd, we will try to do this
                    // when unrolling, so only allow byteable registers as the source value. (We could
                    // consider just using BlkOpKindRepInstr instead.)
                    sourceRegMask = allByteRegs();
                }
#endif // _TARGET_X86_
                break;

            case GenTreeBlk::BlkOpKindRepInstr:
                // rep stos has the following register requirements:
                // a) The memory address to be in RDI.
                // b) The fill value has to be in RAX.
                // c) The buffer size will go in RCX.
                dstAddrRegMask = RBM_RDI;
                sourceRegMask  = RBM_RAX;
                blkSizeRegMask = RBM_RCX;
                break;

            case GenTreeBlk::BlkOpKindHelper:
#ifdef _TARGET_AMD64_
                // The helper follows the regular AMD64 ABI.
                dstAddrRegMask = RBM_ARG_0;
                sourceRegMask  = RBM_ARG_1;
                blkSizeRegMask = RBM_ARG_2;
#else  // !_TARGET_AMD64_
                dstAddrRegMask     = RBM_RDI;
                sourceRegMask      = RBM_RAX;
                blkSizeRegMask     = RBM_RCX;
#endif // !_TARGET_AMD64_
                break;

            default:
                unreached();
        }
    }
    else
    {
        // CopyObj or CopyBlk
        if (source->gtOper == GT_IND)
        {
            assert(source->isContained());
            srcAddrOrFill = source->gtGetOp1();
        }
        if (blkNode->OperGet() == GT_STORE_OBJ)
        {
            if (blkNode->gtBlkOpKind == GenTreeBlk::BlkOpKindRepInstr)
            {
                // We need the size of the contiguous Non-GC-region to be in RCX to call rep movsq.
                blkSizeRegMask = RBM_RCX;
            }
            // The srcAddr must be in a register.  If it was under a GT_IND, we need to subsume all of its
            // sources.
            sourceRegMask  = RBM_RSI;
            dstAddrRegMask = RBM_RDI;
        }
        else
        {
            switch (blkNode->gtBlkOpKind)
            {
                case GenTreeBlk::BlkOpKindUnroll:
                    // If we have a remainder smaller than XMM_REGSIZE_BYTES, we need an integer temp reg.
                    //
                    // x86 specific note: if the size is odd, the last copy operation would be of size 1 byte.
                    // But on x86 only RBM_BYTE_REGS could be used as byte registers.  Therefore, exclude
                    // RBM_NON_BYTE_REGS from internal candidates.
                    if ((size & (XMM_REGSIZE_BYTES - 1)) != 0)
                    {
                        regMaskTP regMask = allRegs(TYP_INT);

#ifdef _TARGET_X86_
                        if ((size & 1) != 0)
                        {
                            regMask &= ~RBM_NON_BYTE_REGS;
                        }
#endif
                        buildInternalIntRegisterDefForNode(blkNode, regMask);
                    }

                    if (size >= XMM_REGSIZE_BYTES)
                    {
                        // If we have a buffer larger than XMM_REGSIZE_BYTES,
                        // reserve an XMM register to use it for a
                        // series of 16-byte loads and stores.
                        buildInternalFloatRegisterDefForNode(blkNode, internalFloatRegCandidates());
                        // Uses XMM reg for load and store and hence check to see whether AVX instructions
                        // are used for codegen, set ContainsAVX flag
                        SetContainsAVXFlags();
                    }
                    break;

                case GenTreeBlk::BlkOpKindRepInstr:
                    // rep stos has the following register requirements:
                    // a) The dest address has to be in RDI.
                    // b) The src address has to be in RSI.
                    // c) The buffer size will go in RCX.
                    dstAddrRegMask = RBM_RDI;
                    sourceRegMask  = RBM_RSI;
                    blkSizeRegMask = RBM_RCX;
                    break;

                case GenTreeBlk::BlkOpKindHelper:
#ifdef _TARGET_AMD64_
                    // The helper follows the regular AMD64 ABI.
                    dstAddrRegMask = RBM_ARG_0;
                    sourceRegMask  = RBM_ARG_1;
                    blkSizeRegMask = RBM_ARG_2;
#else  // !_TARGET_AMD64_
                    dstAddrRegMask = RBM_RDI;
                    sourceRegMask  = RBM_RAX;
                    blkSizeRegMask = RBM_RCX;
#endif // !_TARGET_AMD64_
                    break;

                default:
                    unreached();
            }
        }
        if ((srcAddrOrFill == nullptr) && (sourceRegMask != RBM_NONE))
        {
            // This is a local source; we'll use a temp register for its address.
            assert(source->isContained() && source->OperIsLocal());
            buildInternalIntRegisterDefForNode(blkNode, sourceRegMask);
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