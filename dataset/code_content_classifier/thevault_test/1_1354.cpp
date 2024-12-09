bool ReceivedBlockTransactions(const CBlock &block, CValidationState& state, CBlockIndex *pindexNew, const CDiskBlockPos& pos, const uint256 &hashProof)
{
    pindexNew->nTx = block.vtx.size();
    pindexNew->nChainTx = 0;
    pindexNew->nFile = pos.nFile;
    pindexNew->nDataPos = pos.nPos;
    pindexNew->nUndoPos = 0;
    pindexNew->nStatus |= BLOCK_HAVE_DATA;
    pindexNew->RaiseValidity(BLOCK_VALID_TRANSACTIONS);
    setDirtyBlockIndex.insert(pindexNew);

    // PoSV
    if (block.IsProofOfStake()) {
        pindexNew->SetProofOfStake();
        pindexNew->prevoutStake = block.vtx[1].vin[0].prevout;
        pindexNew->nStakeTime = block.vtx[1].nTime;
    }

    // PoSV
    if (block.IsProofOfStake())
        setStakeSeen.insert(make_pair(pindexNew->prevoutStake, pindexNew->nStakeTime));

    // PoSV: compute stake entropy bit for stake modifier
    if (!pindexNew->SetStakeEntropyBit(block.GetStakeEntropyBit()))
        return state.Invalid(error("ReceivedBlockTransactions() : SetStakeEntropyBit() failed"));

    if (pindexNew->pprev == NULL || pindexNew->pprev->nChainTx) {
        // If pindexNew is the genesis block or all parents are BLOCK_VALID_TRANSACTIONS.
        deque<CBlockIndex*> queue;
        queue.push_back(pindexNew);

        // Recursively process any descendant blocks that now may be eligible to be connected.
        while (!queue.empty()) {
            CBlockIndex *pindex = queue.front();
            queue.pop_front();
            pindex->nChainTx = (pindex->pprev ? pindex->pprev->nChainTx : 0) + pindex->nTx;
            {
                LOCK(cs_nBlockSequenceId);
                pindex->nSequenceId = nBlockSequenceId++;
            }

            // PoSV: Record proof hash value
            uint256 hash = hashProof;
            if (hash == 0) {
            	if (!VerifyHashTarget(block, hash))
            		return state.Invalid(error("%s : VerifyHashTarget() failed", __func__));
            }
            pindex->hashProof = hash;

            // PoSV: compute stake modifier
            uint64_t nStakeModifier = 0;
            bool fGeneratedStakeModifier = false;
            if (!ComputeNextStakeModifier(pindex->pprev, nStakeModifier, fGeneratedStakeModifier))
                return state.Invalid(error("ReceivedBlockTransactions() : ComputeNextStakeModifier() failed"));
            pindex->SetStakeModifier(nStakeModifier, fGeneratedStakeModifier);
            pindex->nStakeModifierChecksum = GetStakeModifierChecksum(pindex);
            if (!CheckStakeModifierCheckpoints(pindex->nHeight, pindex->nStakeModifierChecksum))
                return state.Invalid(error("ReceivedBlockTransactions() : Rejected by stake modifier checkpoint height=%d, modifier=0x%016x", pindex->nHeight, nStakeModifier));

            if (chainActive.Tip() == NULL || !setBlockIndexCandidates.value_comp()(pindex, chainActive.Tip())) {
                setBlockIndexCandidates.insert(pindex);
            }
            std::pair<std::multimap<CBlockIndex*, CBlockIndex*>::iterator, std::multimap<CBlockIndex*, CBlockIndex*>::iterator> range = mapBlocksUnlinked.equal_range(pindex);
            while (range.first != range.second) {
                std::multimap<CBlockIndex*, CBlockIndex*>::iterator it = range.first;
                queue.push_back(it->second);
                range.first++;
                mapBlocksUnlinked.erase(it);
            }
        }
    } else {
        if (pindexNew->pprev && pindexNew->pprev->IsValid(BLOCK_VALID_TREE)) {
            mapBlocksUnlinked.insert(std::make_pair(pindexNew->pprev, pindexNew));
        }
    }

    return true;
}