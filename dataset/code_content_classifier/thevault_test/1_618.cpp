void UnloadBlockIndex()
{
    LOCK(cs_main);
    fHavePruned = false;
    setBlockIndexCandidates.clear();
    chainActive.SetTip(nullptr);
    headersChainActive.SetTip(nullptr);
    pindexBestInvalid = nullptr;
    pindexBestHeader = nullptr;
    mempool.clear();
    mapBlocksUnlinked.clear();
    vinfoBlockFile.clear();
    nLastBlockFile = 0;
    nBlockSequenceId = 1;
    setDirtyBlockIndex.clear();
    g_failed_blocks.clear();
    setDirtyFileInfo.clear();

    for (const BlockMap::value_type& entry : mapBlockIndex) {
        delete entry.second;
    }
    mapBlockIndex.clear();
}