void BenchmarkAssetBuilderWorker::ConvertSettingsToJobParameters(const AzFramework::BenchmarkSettingsAsset& settings,
        AssetBuilderSDK::JobParameterMap& jobParameters)
    {
        jobParameters[AZ_CRC_CE("PrimaryAssetByteSize")] = AZStd::to_string(settings.m_primaryAssetByteSize);
        jobParameters[AZ_CRC_CE("DependentAssetByteSize")] = AZStd::to_string(settings.m_dependentAssetByteSize);
        jobParameters[AZ_CRC_CE("NumAssetsPerDependency")] = AZStd::to_string(settings.m_numAssetsPerDependency);
        jobParameters[AZ_CRC_CE("DependencyDepth")] = AZStd::to_string(settings.m_dependencyDepth);
        jobParameters[AZ_CRC_CE("AssetStorageType")] =
            AZStd::to_string(aznumeric_cast<uint32_t>(settings.m_assetStorageType));
    }