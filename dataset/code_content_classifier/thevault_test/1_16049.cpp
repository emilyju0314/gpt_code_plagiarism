bool ResetSyncCheckpoint()
{
    LOCK(cs_hashSyncCheckpoint);

    // Hash of latest checkpoint
    uint256 checkpointHash = Checkpoints::GetLatestHardenedCheckpoint();

    // Checkpoint block not yet accepted
    if (!mapBlockIndex.count(checkpointHash)) {
        checkpointMessagePending.SetNull();
        hashPendingCheckpoint = checkpointHash;
    }

    if (!WriteSyncCheckpoint((mapBlockIndex.count(checkpointHash) && chainActive.Contains(mapBlockIndex[checkpointHash]))? checkpointHash : Params().HashGenesisBlock()))
        return error("ResetSyncCheckpoint: failed to write sync checkpoint %s", checkpointHash.ToString().c_str());

    return true;
}