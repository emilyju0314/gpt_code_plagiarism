bool CheckProofOfStake(const CTransaction& tx, unsigned int nBits, uint256& hashProofOfStake, uint256& targetProofOfStake)
{
    if (!tx.IsCoinStake())
        return error("CheckProofOfStake() : called on non-coinstake %s", tx.GetHash().ToString().c_str());

    // Kernel (input 0) must match the stake hash target per coin age (nBits)
    const CTxIn& txin = tx.vin[0];

    // First try finding the previous transaction in database
    CTransaction txPrev;
    uint256 hashTxPrev = txin.prevout.hash;
    uint256 hashBlock = 0;
    if (!GetTransaction(hashTxPrev, txPrev, hashBlock, true))
        return error("CheckProofOfStake() : INFO: read txPrev failed"); // previous transaction not in main chain, may occur during initial download

    // Verify signature
    if (!VerifySignature(txPrev, tx, 0))
        return error("CheckProofOfStake() : VerifySignature failed on coinstake %s", tx.GetHash().ToString().c_str());

    // Read block header
    if (!mapBlockIndex.count(hashBlock))
        return error("CheckProofOfStake() : block not indexed"); // unable to read block of previous transaction

    CBlock block;
    if (!ReadBlockFromDisk(block, mapBlockIndex[hashBlock]))
        return error("CheckProofOfStake() : read block failed"); // unable to read block of previous transaction

    if (!CheckStakeKernelHash(nBits, block, txin.prevout.n, txPrev, txin.prevout, tx.nTime, hashProofOfStake, targetProofOfStake, fDebug))
        return error("CheckProofOfStake() : INFO: check kernel failed on coinstake %s, hashProof=%s", tx.GetHash().ToString().c_str(), hashProofOfStake.ToString().c_str()); // may occur during initial download or if behind on block chain sync

    return true;
}