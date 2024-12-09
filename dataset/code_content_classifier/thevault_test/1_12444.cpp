void BenchmarkLoadAllAssets([[maybe_unused]] const AZ::ConsoleCommandContainer& parameters)
    {
        constexpr bool loadBlocking = false;
        BenchmarkLoadAllAssetsInternal(loadBlocking);
    }