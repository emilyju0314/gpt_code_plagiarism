CAuxiliaryBlockRequest::CAuxiliaryBlockRequest(std::deque<const CBlockIndex*> vBlocksToDownloadIn, int64_t createdIn, bool passThroughSignalsIn, const std::function<bool(std::shared_ptr<CAuxiliaryBlockRequest>, const CBlockIndex *pindex)> progressCallbackIn) : vBlocksToDownload(vBlocksToDownloadIn), created(createdIn), passThroughSignals(passThroughSignalsIn), progressCallback(progressCallbackIn)
{
    fCancelled = false;
    requestedUpToSize = 0;
    processedUpToSize = 0;

    NotifyUI();
}