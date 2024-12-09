static void BenchmarkLoadAllAssetsInternal(bool loadBlocking)
    {
        AZStd::vector<AZStd::pair<AZ::Data::AssetId, AZ::Data::AssetType>> assetList;

        // For each asset in the asset catalog, only add it to our list of there's an
        // AssetHandler capable of loading it.
        AZ::Data::AssetCatalogRequests::AssetEnumerationCB collectAssetsCb = [&]
            (const AZ::Data::AssetId id, const AZ::Data::AssetInfo& info)
            {
                if (AZ::Data::AssetManager::Instance().GetHandler(info.m_assetType))
                {
                    assetList.emplace_back(id, info.m_assetType);
                }
            };

        AZ::Data::AssetCatalogRequestBus::Broadcast(&AZ::Data::AssetCatalogRequestBus::Events::EnumerateAssets,
            nullptr, collectAssetsCb, nullptr);

        BenchmarkLoadAssetList(AZStd::move(assetList), loadBlocking);
    }