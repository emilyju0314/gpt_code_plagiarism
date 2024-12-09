void BenchmarkLoadAssetList(AZStd::vector<AZStd::pair<AZ::Data::AssetId, AZ::Data::AssetType>>&& sourceAssetList,
                                bool loadBlocking)
    {
        // Run the entire benchmark on its own thread so that the main thread can continue ticking along.

        AZStd::thread benchmarkThread([assetList = AZStd::move(sourceAssetList), loadBlocking]()
        {
            // Define the set of loading stats to track
            [[maybe_unused]] const size_t initialRequests = assetList.size();
            size_t previouslyLoadedAssets = 0;
            size_t newlyLoadedAssets = 0;
            size_t loadErrors = 0;

            // These are used to hold onto our Asset references until we're done to ensure that we aren't
            // immediately unloading and possibly reloading any assets along the way.
            AZStd::vector<AZ::Data::Asset<AZ::Data::AssetData>> requestedAssets;
            AZStd::vector<AZ::Data::Asset<AZ::Data::AssetData>> processedAssets;

            // Start timing.
            auto start = AZStd::chrono::system_clock::now();

            // Part 1:  Queue up all the requested assets.
            // If loadBlocking is true, each asset will be synchronously and serially loaded.

            for (const auto& [assetId, assetType] : assetList)
            {
                // Check to see if the requested asset is already loaded or not.
                // We'll track the stats appropriately, and queue it if it isn't already loaded.
                AZ::Data::Asset<AZ::Data::AssetData> curAsset;
                curAsset = AZ::Data::AssetManager::Instance().FindAsset(assetId, AZ::Data::AssetLoadBehavior::Default);
                if (curAsset.IsReady())
                {
                    // The asset is already loaded, so track it as processed.
                    previouslyLoadedAssets++;
                    processedAssets.emplace_back(AZStd::move(curAsset));
                }
                else
                {
                    // The asset is *not* already loaded.  Queue it for loading.
                    requestedAssets.emplace_back(AZ::Data::AssetManager::Instance().GetAsset(assetId, assetType, AZ::Data::AssetLoadBehavior::Default));

                    if(loadBlocking)
                    {
                        requestedAssets.back().BlockUntilLoadComplete();
                    }
                }
            }

            // Part 2:  All the assets are queued, now wait for them all to complete.

            AZStd::chrono::milliseconds runMs{ 0 };
            const AZStd::chrono::milliseconds maxWaitMs{ benchmarkLoadAssetTimeoutMs };

            // Keep going until our assets are loaded or we time out.
            while (!requestedAssets.empty() && runMs < maxWaitMs)
            {
                // For all remaining assets, remove any that have finished or errored out
                // and track them in our stats.
                requestedAssets.erase(
                    AZStd::remove_if(requestedAssets.begin(), requestedAssets.end(),
                        [&loadErrors, &newlyLoadedAssets, &processedAssets](auto requestedAsset)
                    {
                        if (!requestedAsset || !requestedAsset.GetId().IsValid())
                        {
                            AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(),
                                "Asset %s type %s (%s) was not found",
                                requestedAsset.GetId().template ToString<AZStd::string>().c_str(),
                                requestedAsset.GetType().template ToString<AZStd::string>().c_str(),
                                requestedAsset.GetHint().c_str());
                            loadErrors++;
                            return true;
                        }
                        else if (requestedAsset.IsReady())
                        {
                            newlyLoadedAssets++;
                            processedAssets.emplace_back(AZStd::move(requestedAsset));
                            return true;
                        }
                        else if (requestedAsset.IsError())
                        {
                            AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(),
                                "Asset %s type %s (%s) had an error while loading",
                                requestedAsset.GetId().template ToString<AZStd::string>().c_str(),
                                requestedAsset.GetType().template ToString<AZStd::string>().c_str(),
                                requestedAsset.GetHint().c_str());
                            loadErrors++;
                            return true;
                        }

                        return false;
                    }),
                    requestedAssets.end());

                // Update our total running time so far.
                runMs = AZStd::chrono::duration_cast<AZStd::chrono::milliseconds>(AZStd::chrono::system_clock::now() - start);

                if (!requestedAssets.empty())
                {
                    // Only display progress messages if requested.  Beware, these can affect the benchmark timings.
                    if (benchmarkLoadAssetDisplayProgress)
                    {
                        AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(),
                            "%zu / %zu processed after %lld ms",
                            (previouslyLoadedAssets + newlyLoadedAssets + loadErrors), initialRequests, runMs.count());
                    }

                    // If polling produces too unstable of results, this could eventually get changed to listen
                    // for all the OnAssetReady messages.
                    AZStd::this_thread::sleep_for(AZStd::chrono::milliseconds(benchmarkLoadAssetPollMs));
                }
            }

            // If we've timed out, provide some diagnostics on what went wrong.
            if (runMs >= maxWaitMs)
            {
                AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(),
                    "Request timed out, the following assets didn't load:\n");
                for (auto& requestedAsset [[maybe_unused]]: requestedAssets)
                {
                    AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(),
                        "%s: id=%s type=%s\n",
                        requestedAsset.GetHint().c_str(),
                        requestedAsset.GetId().template ToString<AZStd::string>().c_str(),
                        requestedAsset.GetType().template ToString<AZStd::string>().c_str()
                    );
                }
            }

            // Print out our benchmarking results.
            AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(),
                "Results: LoadRequests=%zu "
                "PreviouslyLoaded=%zu "
                "NewlyLoaded=%zu "
                "Errors=%zu "
                "TotalProcessed=%zu "
                "Time=%lld ms %s\n",
                initialRequests,
                previouslyLoadedAssets,
                newlyLoadedAssets,
                loadErrors,
                (previouslyLoadedAssets + newlyLoadedAssets + loadErrors),
                runMs.count(), (runMs >= maxWaitMs) ? "(request timed out)" : "");

            AZ_TracePrintf(static_cast<AZ::CVarFixedString>(benchmarkLoadAssetLogLabel).c_str(), "Benchmark run complete.\n");

        });
        benchmarkThread.detach();

    }