int LinearScan::BuildIndir(GenTreeIndir* indirTree)
{
    int srcCount = 0;
    // If this is the rhs of a block copy (i.e. non-enregisterable struct),
    // it has no register requirements.
    if (indirTree->TypeGet() == TYP_STRUCT)
    {
        return srcCount;
    }

    GenTree* addr  = indirTree->Addr();
    GenTree* index = nullptr;
    int      cns   = 0;

#ifdef _TARGET_ARM_
    // Unaligned loads/stores for floating point values must first be loaded into integer register(s)
    if (indirTree->gtFlags & GTF_IND_UNALIGNED)
    {
        var_types type = TYP_UNDEF;
        if (indirTree->OperGet() == GT_STOREIND)
        {
            type = indirTree->AsStoreInd()->Data()->TypeGet();
        }
        else if (indirTree->OperGet() == GT_IND)
        {
            type = indirTree->TypeGet();
        }

        if (type == TYP_FLOAT)
        {
            buildInternalIntRegisterDefForNode(indirTree);
        }
        else if (type == TYP_DOUBLE)
        {
            buildInternalIntRegisterDefForNode(indirTree);
            buildInternalIntRegisterDefForNode(indirTree);
        }
    }
#endif

    if (addr->isContained())
    {
        assert(addr->OperGet() == GT_LEA);
        GenTreeAddrMode* lea = addr->AsAddrMode();
        index                = lea->Index();
        cns                  = lea->Offset();

        // On ARM we may need a single internal register
        // (when both conditions are true then we still only need a single internal register)
        if ((index != nullptr) && (cns != 0))
        {
            // ARM does not support both Index and offset so we need an internal register
            buildInternalIntRegisterDefForNode(indirTree);
        }
        else if (!emitter::emitIns_valid_imm_for_ldst_offset(cns, emitTypeSize(indirTree)))
        {
            // This offset can't be contained in the ldr/str instruction, so we need an internal register
            buildInternalIntRegisterDefForNode(indirTree);
        }
    }

#ifdef FEATURE_SIMD
    if (indirTree->TypeGet() == TYP_SIMD12)
    {
        // If indirTree is of TYP_SIMD12, addr is not contained. See comment in LowerIndir().
        assert(!addr->isContained());

        // Vector3 is read/written as two reads/writes: 8 byte and 4 byte.
        // To assemble the vector properly we would need an additional int register
        buildInternalIntRegisterDefForNode(indirTree);
    }
#endif // FEATURE_SIMD

    srcCount = BuildIndirUses(indirTree);
    buildInternalRegisterUses();

    if (indirTree->gtOper != GT_STOREIND)
    {
        BuildDef(indirTree);
    }
    return srcCount;
}