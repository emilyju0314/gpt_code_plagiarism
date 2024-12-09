void GPUInfoCallback_UpdateCsv(ProcessInfo* processInfo, SwapChainData const& chain, PresentEvent const& p)
{
    auto const& args = GetCommandLineArgs();

    // Don't output dropped frames (if requested).
    auto presented = p.FinalState == PresentResult::Presented;
    if (args.mExcludeDropped && !presented) {
        return;
    }
    /*
    // Early return if not outputing to CSV.
    auto fp = GetOutputCsv(processInfo).mFile;
    if (fp == nullptr) {
        return;
    }
    */
    // Look up the last present event in the swapchain's history.  We need at
    // least two presents to compute frame statistics.
    if (chain.mPresentHistoryCount == 0) {
        return;
    }

    auto lastPresented = chain.mPresentHistory[(chain.mNextPresentIndex - 1) % SwapChainData::PRESENT_HISTORY_MAX_COUNT].get();

    // Compute frame statistics.
    double timeInSeconds = QpcToSeconds(p.QpcTime);
    double msBetweenPresents = 1000.0 * QpcDeltaToSeconds(p.QpcTime - lastPresented->QpcTime);
    double msInPresentApi = 1000.0 * QpcDeltaToSeconds(p.TimeTaken);
    double msUntilRenderComplete = 0.0;
    double msUntilDisplayed = 0.0;
    double msBetweenDisplayChange = 0.0;

    if (args.mVerbosity > Verbosity::Simple) {
        if (p.ReadyTime > 0) {
            msUntilRenderComplete = 1000.0 * QpcDeltaToSeconds(p.ReadyTime - p.QpcTime);
        }
        if (presented) {
            msUntilDisplayed = 1000.0 * QpcDeltaToSeconds(p.ScreenTime - p.QpcTime);

            if (chain.mLastDisplayedPresentIndex > 0) {
                auto lastDisplayed = chain.mPresentHistory[chain.mLastDisplayedPresentIndex % SwapChainData::PRESENT_HISTORY_MAX_COUNT].get();
                msBetweenDisplayChange = 1000.0 * QpcDeltaToSeconds(p.ScreenTime - lastDisplayed->ScreenTime);
            }
        }
    }

    GPUInfoCsvData gpuInfoCsvData;

    gpuInfoCsvData.processName = processInfo->mModuleName.c_str(),
    gpuInfoCsvData.processId = p.ProcessId, p.SwapChainAddress,
    gpuInfoCsvData.runTime = RuntimeToString(p.Runtime),
    gpuInfoCsvData.syncInterval = p.SyncInterval,
    gpuInfoCsvData.flags = p.PresentFlags;

    // Output in CSV format
    gpuInfoCsvData.supportsTearing = p.SupportsTearing;
    gpuInfoCsvData.presentMode = PresentModeToString(p.PresentMode);
    gpuInfoCsvData.wasBatched = p.WasBatched;
    gpuInfoCsvData.dwmNotified = p.DwmNotified;

    gpuInfoCsvData.finalState = FinalStateToDroppedString(p.FinalState);
    gpuInfoCsvData.timeInSeconds = timeInSeconds;
    gpuInfoCsvData.msBetweenPresents = msBetweenPresents;
    gpuInfoCsvData.msBetweenDisplayChange = msBetweenDisplayChange;

    gpuInfoCsvData.msInPresentApi = msInPresentApi;

    gpuInfoCsvData.msUntilRenderComplete = msUntilRenderComplete,
    gpuInfoCsvData.msUntilDisplayed =  msUntilDisplayed;

    gpuInfoCsvData.outputQpcTime = p.QpcTime;

    time(&gpuInfoCsvData.time);

    if (g_gpuInfo.m_pgpuInfoCallback != 0) {
        g_gpuInfo.m_pgpuInfoCallback->notifyHostCsvData(gpuInfoCsvData);
    }

}