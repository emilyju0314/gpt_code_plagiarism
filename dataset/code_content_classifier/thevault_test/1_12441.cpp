void BenchmarkClearAssetList([[maybe_unused]] const AZ::ConsoleCommandContainer& parameters)
    {
        s_benchmarkAssetList.clear();
        AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(), "Benchmark asset list cleared.\n");
    }