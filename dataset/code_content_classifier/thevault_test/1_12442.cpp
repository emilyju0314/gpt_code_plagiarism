void BenchmarkLoadAssetList(const AZ::ConsoleCommandContainer& parameters)
    {
        BenchmarkAddAssetsToList(parameters);

        if (!s_benchmarkAssetList.empty())
        {
            constexpr bool loadBlocking = false;

            // This intentionally does a 'move' of the list instead of a copy as a user convenience.  The assumed common use case
            // is that once the user has run a benchmark, they would like the asset list cleared before starting the next benchmark run.
            BenchmarkLoadAssetList(AZStd::move(s_benchmarkAssetList), loadBlocking);
        }
    }