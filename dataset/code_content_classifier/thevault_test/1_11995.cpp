void BenchmarkAssetBuilderWorker::CreateJobs(const AssetBuilderSDK::CreateJobsRequest& request,
                                                 AssetBuilderSDK::CreateJobsResponse& response)
    {
        if (m_isShuttingDown)
        {
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::ShuttingDown;
            return;
        }

        AZStd::string ext;
        constexpr bool includeDot = false;
        AZ::StringFunc::Path::GetExtension(request.m_sourceFile.c_str(), ext, includeDot);

        // If we're reprocessing a benchmark asset, just ignore it.  There's no reason these should change
        // outside of the generation process below.
        if (AZ::StringFunc::Equal(ext.c_str(), AzFramework::s_benchmarkAssetExtension))
        {
            AZ_TracePrintf(AssetBuilderSDK::InfoWindow,
                           "Request to process benchmark asset ignored: %s\n", request.m_sourceFile.c_str()); 
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
            return;
        }

        // Load the benchmark asset settings file to determine how to generate the benchmark assets.
        // The FilterDescriptor is here to ensure that we don't try to load any dependent BenchmarkAsset
        // assets when loading the BenchmarkSettings.
        AZStd::string fullPath;
        AZ::StringFunc::Path::Join(request.m_watchFolder.c_str(), request.m_sourceFile.c_str(), fullPath, true, true);
        AZStd::unique_ptr<AzFramework::BenchmarkSettingsAsset> settingsPtr(
            AZ::Utils::LoadObjectFromFile<AzFramework::BenchmarkSettingsAsset>(
                fullPath, nullptr, AZ::Utils::FilterDescriptor(&AZ::Data::AssetFilterNoAssetLoading))
        );

        // Validate that the settings load successfully, and that the combination of settings
        // won't blow up and create an excessive amount of data.
        if (!ValidateSettings(settingsPtr))
        {
            AZ_Error(AssetBuilderSDK::ErrorWindow, false,
                     "Error during settings validation: %s.\n",  request.m_sourceFile.c_str());
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Failed;
            return;
        }

        // Generate the benchmark assets for all platforms
        for (const AssetBuilderSDK::PlatformInfo& info : request.m_enabledPlatforms)
        {
            AssetBuilderSDK::JobDescriptor descriptor;
            descriptor.m_jobKey = "Benchmark Asset Generation";
            descriptor.SetPlatformIdentifier(info.m_identifier.data());
            descriptor.m_critical = false;

            // Save off the generation parameters so that we can access them during job processing.
            ConvertSettingsToJobParameters(*settingsPtr, descriptor.m_jobParameters);

            response.m_createJobOutputs.push_back(descriptor);
        }

        // We don't need to save off any SourceFileDependency info here, since the BenchmarkSettings
        // should be the only source file.

        response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
        return;
    }