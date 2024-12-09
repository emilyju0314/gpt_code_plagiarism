bool IsBlockValueValid(const CBlock& block, int nBlockHeight, CAmount blockReward, std::string& strErrorRet)
{
    strErrorRet = "";

    bool isBlockRewardValueMet = (block.vtx[0].GetValueOut() <= blockReward);
    if (fDebug)
        LogPrintf("block.vtx[0].GetValueOut() %lld <= blockReward %lld\n", block.vtx[0].GetValueOut(), blockReward);

    // we are still using budgets, but we have no data about them anymore,
    // all we know is predefined budget cycle and window
    if (!vnodeSync.IsSynced()) {
        if (!isBlockRewardValueMet) {
            strErrorRet = strprintf("coinbase pays too much at height %d (actual=%d vs limit=%d), exceeded block reward, only regular blocks are allowed at this height",
                nBlockHeight, block.vtx[0].GetValueOut(), blockReward);
        }

        // it MUST be a regular block otherwise
        return isBlockRewardValueMet;
    }

    // we are synced, let's try to check as much data as we can

    // should NOT allow superblocks at all, when superblocks are disabled
    LogPrint("gobject", "IsBlockValueValid -- Superblocks are disabled, no superblocks allowed\n");
    if (!isBlockRewardValueMet) {
        strErrorRet = strprintf("coinbase pays too much at height %d (actual=%d vs limit=%d), exceeded block reward, superblocks are disabled",
            nBlockHeight, block.vtx[0].GetValueOut(), blockReward);
    }

    // it MUST be a regular block
    return isBlockRewardValueMet;
}