void GPUInfoCallback_UpdateConsole(uint32_t processId, ProcessInfo const& processInfo)
{
//    auto const& args = GetCommandLineArgs();
/*
    // Don't display non-target or empty processes
    if (!processInfo.mTargetProcess ||
        processInfo.mModuleName.empty() ||
        processInfo.mSwapChain.empty()) {
        return;
    }
*/
    GPUInfoConsoleData gpuInfoConsoleData;

    gpuInfoConsoleData.processId = NULL;

    auto empty = true;

    for (auto const& pair : processInfo.mSwapChain) {
        auto address = pair.first;
        auto const& chain = pair.second;

        // Only show swapchain data if there at least two presents in the
        // history.
        if (chain.mPresentHistoryCount < 2) {
            continue;
        }

        if (empty) {
            empty = false;
//            ConsolePrintLn("%s[%d]:", processInfo.mModuleName.c_str(), processId);
            gpuInfoConsoleData.processName = processInfo.mModuleName;
            gpuInfoConsoleData.processId = processId;
        }

        if (gpuInfoConsoleData.processId == NULL) {
            continue;
        }

        auto const& present0 = *chain.mPresentHistory[(chain.mNextPresentIndex - chain.mPresentHistoryCount) % SwapChainData::PRESENT_HISTORY_MAX_COUNT];
        auto const& presentN = *chain.mPresentHistory[(chain.mNextPresentIndex - 1) % SwapChainData::PRESENT_HISTORY_MAX_COUNT];
        auto cpuAvg = QpcDeltaToSeconds(presentN.QpcTime - present0.QpcTime) / (chain.mPresentHistoryCount - 1);

        gpuInfoConsoleData.address = (int)address;
        gpuInfoConsoleData.runTime = RuntimeToString(presentN.Runtime);
        gpuInfoConsoleData.syncInterval = presentN.SyncInterval;
        gpuInfoConsoleData.flags = presentN.PresentFlags;
        gpuInfoConsoleData.framemSecs = 1000.0 * cpuAvg;
        gpuInfoConsoleData.fps = 1.0 / cpuAvg;

        /*
        ConsolePrint("    %016llX (%s): SyncInterval=%d Flags=%d %.2lf ms/frame (%.1lf fps",
            address,
            RuntimeToString(presentN.Runtime),
            presentN.SyncInterval,
            presentN.PresentFlags,
            1000.0 * cpuAvg,
            1.0 / cpuAvg);
        */
            /*
        size_t displayCount = 0;
        uint64_t latencySum = 0;
        uint64_t display0ScreenTime = 0;
        PresentEvent* displayN = nullptr;
        if (args.mVerbosity > Verbosity::Simple) {
            for (uint32_t i = 0; i < chain.mPresentHistoryCount; ++i) {
                auto const& p = chain.mPresentHistory[(chain.mNextPresentIndex - chain.mPresentHistoryCount + i) % SwapChainData::PRESENT_HISTORY_MAX_COUNT];
                if (p->FinalState == PresentResult::Presented) {
                    if (displayCount == 0) {
                        display0ScreenTime = p->ScreenTime;
                    }
                    displayN = p.get();
                    latencySum += p->ScreenTime - p->QpcTime;
                    displayCount += 1;
                }
            }
        }

        if (displayCount >= 2) {
            ConsolePrint(", %.1lf fps displayed", (double)(displayCount - 1) / QpcDeltaToSeconds(displayN->ScreenTime - display0ScreenTime));
        }

        if (displayCount >= 1) {
            ConsolePrint(", %.2lf ms latency", 1000.0 * QpcDeltaToSeconds(latencySum) / displayCount);
        }

        ConsolePrint(")");

        if (displayCount > 0) {
            ConsolePrint(" %s", PresentModeToString(displayN->PresentMode));
        }

        ConsolePrintLn("");
        */
    }
    /*
    if (!empty) {
        ConsolePrintLn("");
    } */

    time(&gpuInfoConsoleData.time);

    if (!empty) {
        if (g_gpuInfo.m_pgpuInfoCallback != 0) {
            g_gpuInfo.m_pgpuInfoCallback->notifyHostConsoleData(gpuInfoConsoleData);
        }
    }
}