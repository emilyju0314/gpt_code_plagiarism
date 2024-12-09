void BenchmarkLoadAllAssetsSynchronous([[maybe_unused]] const AZ::ConsoleCommandContainer& parameters)
    {
        constexpr bool loadBlocking = true;
        BenchmarkLoadAllAssetsInternal(loadBlocking);
    }