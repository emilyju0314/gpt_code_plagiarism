void BenchmarkAssetBuilderWorker::ConvertJobParametersToSettings(const AssetBuilderSDK::JobParameterMap& jobParameters,
        AzFramework::BenchmarkSettingsAsset& settings)
    {
        settings.m_primaryAssetByteSize = AZStd::stoul(jobParameters.at(AZ_CRC_CE("PrimaryAssetByteSize")));
        settings.m_dependentAssetByteSize = AZStd::stoul(jobParameters.at(AZ_CRC_CE("DependentAssetByteSize")));
        settings.m_numAssetsPerDependency = AZStd::stoul(jobParameters.at(AZ_CRC_CE("NumAssetsPerDependency")));
        settings.m_dependencyDepth = AZStd::stoul(jobParameters.at(AZ_CRC_CE("DependencyDepth")));
        settings.m_assetStorageType = static_cast<AZ::DataStream::StreamType>(
            AZStd::stoul(jobParameters.at(AZ_CRC_CE("AssetStorageType"))));
    }