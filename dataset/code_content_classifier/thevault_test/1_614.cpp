static bool AcceptBlock(const std::shared_ptr<const CBlock>& pblock, CValidationState& state, const CChainParams& chainparams, CBlockIndex** ppindex, bool fRequested, const CDiskBlockPos* dbp, bool* fNewBlock, bool onlyHeaderCheck = false)
{
    const CBlock& block = *pblock;

    if (fNewBlock) *fNewBlock = false;
    AssertLockHeld(cs_main);

    CBlockIndex *pindexDummy = nullptr;
    CBlockIndex *&pindex = ppindex ? *ppindex : pindexDummy;

    if (!AcceptBlockHeader(block, state, chainparams, &pindex))
        return false;

    bool fAlreadyHave = pindex->nStatus & BLOCK_HAVE_DATA;

    // don't validate the block if we fetch it with a auxiliary CAuxiliaryBlockRequest
    if (onlyHeaderCheck) {
        LogPrint("net", "Accept specific block %s (%d)\n", pindex->GetBlockHash().ToString(), pindex->nHeight);
        if (fAlreadyHave) return true;
    }
    else
    {
        // Try to process all requested blocks that we don't have, but only
        // process an unrequested block if it's new and has enough work to
        // advance our tip, and isn't too many blocks ahead.
        bool fHasMoreOrSameWork = (chainActive.Tip() ? pindex->nChainWork >= chainActive.Tip()->nChainWork : true);
        // Blocks that are too out-of-order needlessly limit the effectiveness of
        // pruning, because pruning will not delete block files that contain any
        // blocks which are too close in height to the tip.  Apply this test
        // regardless of whether pruning is enabled; it should generally be safe to
        // not process unrequested blocks.
        bool fTooFarAhead = (pindex->nHeight > int(chainActive.Height() + MIN_BLOCKS_TO_KEEP));

        // TODO: Decouple this function from the block download logic by removing fRequested
        // This requires some new chain datastructure to efficiently look up if a
        // block is in a chain leading to a candidate for best tip, despite not
        // being such a candidate itself.

        // TODO: deal better with return value and error conditions for duplicate
        // and unrequested blocks.
        if (fAlreadyHave) return true;
        if (!fRequested) {  // If we didn't ask for it:
            if (pindex->nTx != 0) return true;    // This is a previously-processed block that was pruned
            if (!fHasMoreOrSameWork) return true; // Don't process less-work chains
            if (fTooFarAhead) return true;        // Block height is too high

            // Protect against DoS attacks from low-work chains.
            // If our tip is behind, a peer could try to send us
            // low-work blocks on a fake chain that we would never
            // request; don't process these.
            if (pindex->nChainWork < nMinimumChainWork) return true;
        }
        if (fNewBlock) *fNewBlock = true;

        if (!CheckBlock(block, state, chainparams.GetConsensus(), GetAdjustedTime()) ||
            !ContextualCheckBlock(block, state, pindex->pprev)) {
            if (state.IsInvalid() && !state.CorruptionPossible()) {
                pindex->nStatus |= BLOCK_FAILED_VALID;
                setDirtyBlockIndex.insert(pindex);
            }
            return error("%s: %s", __func__, FormatStateMessage(state));
        }
    }

    // Header is valid/has work, merkle tree and segwit merkle tree are good...RELAY NOW
    // (but if it does not build on our best tip, let the SendMessages loop relay it)
    if (!IsInitialBlockDownload() && chainActive.Tip() == pindex->pprev)
        GetMainSignals().NewPoWValidBlock(pindex, pblock);

    int nHeight = pindex->nHeight;

    // Write block to history file
    try {
        unsigned int nBlockSize = ::GetSerializeSize(block, SER_DISK, CLIENT_VERSION);
        CDiskBlockPos blockPos;
        if (dbp != nullptr)
            blockPos = *dbp;
        if (!FindBlockPos(state, blockPos, nBlockSize+8, nHeight, block.GetBlockTime(), dbp != nullptr))
            return error("AcceptBlock() : FindBlockPos failed");
        if (dbp == nullptr)
            if (!WriteBlockToDisk(block, blockPos, chainparams.MessageStart()))
                return AbortNode(state, "Failed to write block"); // QA: followup.
        if (!ReceivedBlockTransactions(block, state, pindex, blockPos))
            return error("AcceptBlock() : ReceivedBlockTransactions failed");
    } catch (const std::runtime_error& e) {
        return AbortNode(state, std::string("System error: ") + e.what());
    }

    FlushStateToDisk(state, FLUSH_STATE_NONE);

    return true;
}