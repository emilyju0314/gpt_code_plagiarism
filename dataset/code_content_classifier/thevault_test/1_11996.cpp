void BenchmarkAssetBuilderWorker::ProcessJob(const AssetBuilderSDK::ProcessJobRequest& request,
                                                 AssetBuilderSDK::ProcessJobResponse& response)
    {
        // Before we begin, let's make sure we are not meant to abort.
        {
            AssetBuilderSDK::JobCancelListener jobCancelListener(request.m_jobId);
            if (jobCancelListener.IsCancelled())
            {
                AZ_Warning(AssetBuilderSDK::WarningWindow, false,
                           "Cancel Request: Cancelled benchmark asset generation job for %s.\n", request.m_fullPath.data());
                response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
                return;
            }

            if (m_isShuttingDown)
            {
                AZ_Warning(AssetBuilderSDK::WarningWindow, false,
                           "Shutdown Request: Cancelled benchmark asset generation job for %s.\n", request.m_fullPath.data());
                response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
                return;
            }
        }

        AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "Performing benchmark asset generation job for %s\n", request.m_fullPath.data());

        // Fetch the settings parameters for our asset generation.
        AzFramework::BenchmarkSettingsAsset settings;
        ConvertJobParametersToSettings(request.m_jobDescription.m_jobParameters, settings);

        // Construct the output path name for the BenchmarkSettings file.  This will get saved into a temp directory.
        // The Asset Processor will handle copying the files from the temp directory to the cache on successful completion.
        AZStd::string fileName;
        AZStd::string destPath;
        AZ::StringFunc::Path::GetFullFileName(request.m_fullPath.c_str(), fileName);
        AZ::StringFunc::Path::ConstructFull(request.m_tempDirPath.c_str(), fileName.c_str(), destPath, true);

        // Copy the original BenchmarkSettings file directly into the output.
        // This is necessary to open the file in the Asset Editor inside the LY Editor.
        // Otherwise, we can *create* the BenchmarkSettings file with the Asset Editor,
        // but if we try to re-open it, the Asset Editor will try to open a BenchmarkAsset file instead.
        {
            AZ::IO::LocalFileIO fileIO;
            if (fileIO.Copy(request.m_fullPath.c_str(), destPath.c_str()) != AZ::IO::ResultCode::Success)
            {
                AZ_Error(AssetBuilderSDK::ErrorWindow, false,
                         "Error copying original benchmarksettings file: %s\n", request.m_fullPath.c_str());
                response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Failed;
                return;
            }

            // Save a reference to it in the output products.
            // We intentionally mark "dependencies handled" with no dependencies added.  Even though
            // we generate BenchmarkAsset files, we don't need to directly create dependencies bewteen the
            // BenchmarkSettings file and the generated BenchmarkAsset assets.
            AssetBuilderSDK::JobProduct jobProduct(destPath);
            jobProduct.m_productAssetType = azrtti_typeid<AzFramework::BenchmarkSettingsAsset>();
            jobProduct.m_productSubID = 0;
            jobProduct.m_dependencies.clear();
            jobProduct.m_dependenciesHandled = true;
            response.m_outputProducts.push_back(jobProduct);
        }

        // Now, generate all of the BenchmarkAsset files from the provided BenchmarkSettings.
        // This will recursively generate assets from the final leaf assets backwards so that we
        // only create assets when its dependencies already exist and can be linked to.
        {
            constexpr uint32_t curDepth = 0;
            uint32_t uniqueSubId = 1;

            // Our primary generated asset will always have the same base name as the settings file,
            // just with a different extension.
            AZStd::string generatedAssetPath(destPath);
            AZ::StringFunc::Path::ReplaceExtension(generatedAssetPath, AzFramework::s_benchmarkAssetExtension);

            response.m_resultCode = GenerateDependentAssetSubTree(settings, request.m_sourceFileUUID, request.m_sourceFile,
                                                                  generatedAssetPath, curDepth, uniqueSubId, response);
        }
    }