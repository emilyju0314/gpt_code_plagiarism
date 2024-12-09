void EditorImageBuilderWorker::CreateJobs(const AssetBuilderSDK::CreateJobsRequest& request, AssetBuilderSDK::CreateJobsResponse& response)
    {
        AZStd::string fullPath;
        AzFramework::StringFunc::Path::Join(request.m_watchFolder.data(), request.m_sourceFile.data(), fullPath, true, true);

        // Check file for _GSI suffix/pattern which assumes processing will occur whether or not settings are provided
        AZStd::string patternPath = fullPath;
        AZStd::to_upper(patternPath.begin(), patternPath.end());
        bool patternMatched = patternPath.rfind("_GSI.") != AZStd::string::npos;

        // Determine if a settings file has been provided
        AZStd::string settingsPath = fullPath + "." + s_gradientImageSettingsExtension;
        bool settingsExist = AZ::IO::SystemFile::Exists(settingsPath.data());

        // If the settings file is modified the image must be reprocessed
        AssetBuilderSDK::SourceFileDependency sourceFileDependency;
        sourceFileDependency.m_sourceFileDependencyPath = settingsPath;
        response.m_sourceFileDependencyList.push_back(sourceFileDependency);

        // If no settings file was provided then skip the file, unless the file name matches the convenience pattern
        if (!patternMatched && !settingsExist)
        {
            //do nothing if settings aren't provided
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
            return;
        }

        AZStd::unique_ptr<ImageSettings> settingsPtr;
        if (settingsExist)
        {
            settingsPtr.reset(AZ::Utils::LoadObjectFromFile<ImageSettings>(settingsPath));
        }

        // If the settings file didn't load then skip the file, unless the file name matches the convenience pattern
        if (!patternMatched && !settingsPtr)
        {
            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Failed to create gradient image conversion job for %s.\nFailed loading settings %s.\n", fullPath.data(), settingsPath.data());
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Failed;
            return;
        }

        // If settings loaded but processing is disabled then skip the file
        if (settingsPtr && !settingsPtr->m_shouldProcess)
        {
            //do nothing if settings disable processing
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
            return;
        }

        // Get the extension of the file
        AZStd::string ext;
        AzFramework::StringFunc::Path::GetExtension(request.m_sourceFile.data(), ext, false);
        AZStd::to_upper(ext.begin(), ext.end());

        // We process the same file for all platforms
        for (const AssetBuilderSDK::PlatformInfo& info : request.m_enabledPlatforms)
        {
            AssetBuilderSDK::JobDescriptor descriptor;
            descriptor.m_jobKey = ext + " Compile (Gradient Image)";
            descriptor.SetPlatformIdentifier(info.m_identifier.data());
            descriptor.m_critical = false;
            response.m_createJobOutputs.push_back(descriptor);
        }

        response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
        return;
    }