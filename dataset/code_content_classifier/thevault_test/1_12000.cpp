AssetBuilderSDK::ProcessJobResultCode BenchmarkAssetBuilderWorker::GenerateDependentAssetSubTree(
                const AzFramework::BenchmarkSettingsAsset& settings,
                AZ::Uuid sourceUuid,
                const AZStd::string& sourceAssetPath,
                const AZStd::string& generatedAssetPath,
                uint32_t curDepth,
                uint32_t& uniqueSubId,
                AssetBuilderSDK::ProcessJobResponse& response)
    {
        uint32_t thisAssetSubId = uniqueSubId++;

        // Create a unique asset name by appending the asset's subID to the name.
        // This gives us a name that's both unique and predictable / uniform in size.
        AZStd::string baseName;
        AZ::StringFunc::Path::GetFileName(generatedAssetPath.c_str(), baseName);
        AZStd::string newBaseName = AZStd::string::format("%s_%08X", baseName.c_str(), thisAssetSubId);
        AZStd::string destPath(generatedAssetPath);
        AZ::StringFunc::Path::ReplaceFullName(destPath, newBaseName.c_str(), AzFramework::s_benchmarkAssetExtension);

        // Create our benchmark asset.
        AzFramework::BenchmarkAsset asset;
        asset.m_bufferSize = (curDepth == 0) ? settings.m_primaryAssetByteSize : settings.m_dependentAssetByteSize;
        asset.m_assetReferences.clear();
        asset.m_buffer.resize(asset.m_bufferSize);

        // Fill the buffer with deterministically random numbers.
        // For our random seed, we'll use the hash of the base file name.  The path isn't used in the hash
        // to ensure that we're producing deterministic results across PCs using different drives or base paths.
        FillBuffer(asset.m_buffer, asset.m_bufferSize, AZStd::hash<AZStd::string>()(newBaseName));

        // Recursively create the nested dependency tree.
        if (curDepth < settings.m_dependencyDepth)
        {
            for (uint32_t dependentAssetNum = 0; dependentAssetNum < settings.m_numAssetsPerDependency; dependentAssetNum++)
            {
                // Add the topmost asset of the tree we're about to generate to our list of direct asset references
                // inside our generated BenchmarkAsset.
                // Because we're using sub IDs, the "hint" path uses the original source path, not
                // the output name of the sub-asset.
                AZ::Data::AssetId dependentAssetId(sourceUuid, uniqueSubId);
                AZ::Data::Asset<AzFramework::BenchmarkAsset> dependentAsset(dependentAssetId,
                    azrtti_typeid<AzFramework::BenchmarkAsset>(), sourceAssetPath);
                // Force each dependent asset to use a PreLoad behavior to ensure that it needs to load before the topmost
                // benchmark asset load is considered complete.
                dependentAsset.SetAutoLoadBehavior(AZ::Data::AssetLoadBehavior::PreLoad);
                asset.m_assetReferences.emplace_back(dependentAsset);

                // Recursively generate the dependent asset and everything it depends on.
                AssetBuilderSDK::ProcessJobResultCode result = GenerateDependentAssetSubTree(
                    settings, sourceUuid, sourceAssetPath,
                    generatedAssetPath, curDepth + 1, uniqueSubId, response);

                if (result != AssetBuilderSDK::ProcessJobResult_Success)
                {
                    return result;
                }
            }
        }

        // Now that we've finished creating all the dependent assets, serialize out our created asset.
        bool success = AZ::Utils::SaveObjectToFile<AzFramework::BenchmarkAsset>(
            destPath, settings.m_assetStorageType, &asset);

        if (!success)
        {
            AZ_Error(AssetBuilderSDK::ErrorWindow, false,
                     "Error while saving generated file: %s\n", destPath.c_str());
            return AssetBuilderSDK::ProcessJobResult_Failed;
        }

        // Create our output JobProduct record with the appropriate calculated dependencies.
        // Note that we use a simple always-incrementing subID scheme for our generated assets,
        // so that they appear as subIDs 1-N.  The original BenchmarkSettings asset will always have subID 0.
        // This isn't strictly correct, since the subIDs aren't stable for the outputs if the input settings
        // change, but since we're always generating all the outputs it shouldn't cause any problems.
        AssetBuilderSDK::JobProduct jobProduct;
        if (!AssetBuilderSDK::OutputObject(&asset, destPath, azrtti_typeid<AzFramework::BenchmarkAsset>(),
                                           thisAssetSubId, jobProduct))
        {
            AZ_Error(AssetBuilderSDK::ErrorWindow, false, "Failed to output product dependencies.");
            return AssetBuilderSDK::ProcessJobResult_Failed;
        }
        response.m_outputProducts.push_back(jobProduct);

        return AssetBuilderSDK::ProcessJobResult_Success;
    }