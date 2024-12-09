bool VerifyHashTarget(const CBlock& block, uint256& hashProof)
{
	AssertLockHeld(cs_main);

	uint256 hash = block.GetHash();

	if (hash != Params().HashGenesisBlock()) {

		// Verify hash target and signature of coinstake tx
		if (block.IsProofOfStake())
		{
			if (fDebug)
				LogPrintf("ProofOfStake: VerifyHashTarget(): hash %s, nBits %i\n", block.vtx[1].GetHash().ToString().c_str(), block.nBits);

			uint256 targetProofOfStake;
			if (!CheckProofOfStake(block.vtx[1], block.nBits, hashProof, targetProofOfStake))
			{
				LogPrintf("WARNING: VerifyHashTarget(): check proof-of-stake failed for block %s\n", hash.ToString());
				return false; // do not error here as we expect this during initial block download
			}
		}
		else if (block.IsProofOfWork())
		{
			// PoW is checked in CheckBlock()
			hashProof = block.GetPoWHash();
		}
	}
	hashProof = 0;

	return true;
}