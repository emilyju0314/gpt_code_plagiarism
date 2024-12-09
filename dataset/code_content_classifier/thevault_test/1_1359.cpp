bool CWallet::SignBlock(CBlock *pblock, CAmount& nFees)
{
    // if we are trying to sign something other than proof-of-stake block template
    if (!pblock->vtx[0].vout[0].IsEmpty())
        return false;

    // if we are trying to sign
    //    a complete proof-of-stake block
    if (pblock->IsProofOfStake())
        return true;

    static int64_t nLastCoinStakeSearchTime = GetAdjustedTime(); // startup timestamp

    CKey key;
    CMutableTransaction txCoinStake;
    CMutableTransaction txCoinbase(pblock->vtx[0]);
    int64_t nSearchTime = txCoinStake.nTime; // search to current time
    CBlockIndex *pindexBest = chainActive.Tip();
    int nPosvVer = 1;

    if (nSearchTime > nLastCoinStakeSearchTime) {
        if (fDebug) {
            LogPrintf("SignBlock : about to create coinstake: nFees=%ld\n", nFees);
            LogPrintf("SignBlock : SuperMajority = %s\n", CBlockIndex::IsSuperMajority(5, pindexBest->pprev, Params().EnforceBlockUpgradeMajority_5()));
        }

        if (CBlockIndex::IsSuperMajority(5, pindexBest->pprev, Params().EnforceBlockUpgradeMajority_5())) {
            nPosvVer = 2;
        }

        if (CreateCoinStake(pblock->nBits, nSearchTime - nLastCoinStakeSearchTime, nFees, txCoinStake, key, nPosvVer)) {
            LogPrintf("SignBlock : coinstake created: nFees=%ld\n", nFees);
            if (txCoinStake.nTime >= max(pindexBest->GetMedianTimePast()+1, PastDrift(pindexBest->GetBlockTime())))
            {
                // make sure coinstake would meet timestamp protocol
                //    as it would be the same as the block timestamp
            	txCoinbase.nTime = pblock->nTime = txCoinStake.nTime;
            	pblock->vtx[0] = txCoinbase;
                pblock->nTime = max(pindexBest->GetMedianTimePast()+1, pblock->GetMaxTransactionTime());
                pblock->nTime = max(pblock->GetBlockTime(), PastDrift(pindexBest->GetBlockTime()));

                // we have to make sure that we have no future timestamps in
                //    our transactions set
                for (vector<CTransaction>::iterator it = pblock->vtx.begin(); it != pblock->vtx.end();)
                    if (it->nTime > pblock->nTime) { it = pblock->vtx.erase(it); } else { ++it; }

                pblock->vtx.insert(pblock->vtx.begin() + 1, txCoinStake);
                pblock->hashMerkleRoot = pblock->BuildMerkleTree();

                // append a signature to our block
                return key.Sign(pblock->GetHash(), pblock->vchBlockSig);
            }
        }
        nLastCoinStakeSearchInterval = nSearchTime - nLastCoinStakeSearchTime;
        nLastCoinStakeSearchTime = nSearchTime;
    }

    return false;
}