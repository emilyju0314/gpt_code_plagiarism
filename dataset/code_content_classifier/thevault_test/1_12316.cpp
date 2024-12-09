void EditorImageBuilderWorker::ProcessJob(const AssetBuilderSDK::ProcessJobRequest& request, AssetBuilderSDK::ProcessJobResponse& response)
    {
        // Before we begin, let's make sure we are not meant to abort.
        AssetBuilderSDK::JobCancelListener jobCancelListener(request.m_jobId);
        if (jobCancelListener.IsCancelled())
        {
            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Cancelled gradient image conversion job for %s.\nCancellation requested.\n", request.m_fullPath.data());
            response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
            return;
        }

        if (m_isShuttingDown)
        {
            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Cancelled gradient image conversion job for %s.\nShutdown requested.\n", request.m_fullPath.data());
            response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
            return;
        }

        // Do conversion and get exported file's path
        AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "Performing gradient image conversion job for %s\n", request.m_fullPath.data());

        auto imageAsset = LoadImageFromPath(request.m_fullPath);

        if (!imageAsset)
        {
            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Failed gradient image conversion job for %s.\nFailed loading source image %s.\n", request.m_fullPath.data(), request.m_fullPath.data());
            return;
        }

        auto imageSettings = LoadImageSettingsFromPath(request.m_fullPath);

        if (!imageSettings)
        {
            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Failed gradient image conversion job for %s.\nFailed loading source image %s.\n", request.m_fullPath.data(), request.m_fullPath.data());
            return;
        }

        // ChannelMask is 8 bits, and the bits are assumed to be as follows: 0b0000ABGR
        imageAsset = ConvertImage(*imageAsset, *imageSettings);

        //generate export file name
        QDir dir(request.m_tempDirPath.data());
        if (!dir.exists())
        {
            dir.mkpath(".");
        }

        AZStd::string fileName;
        AZStd::string outputPath;
        AzFramework::StringFunc::Path::GetFileName(request.m_fullPath.data(), fileName);
        fileName += AZStd::string(".") + s_gradientImageExtension;
        AzFramework::StringFunc::Path::Join(request.m_tempDirPath.data(), fileName.data(), outputPath, true, true);
        AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "Output path for gradient image conversion: %s\n", outputPath.data());

        //save asset
        if (!AZ::Utils::SaveObjectToFile(outputPath, AZ::DataStream::ST_XML, imageAsset.get()))
        {
            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Failed gradient image conversion job for %s.\nFailed saving output file %s.\n", request.m_fullPath.data(), outputPath.data());
            return;
        }

        // Report the image-import result
        AssetBuilderSDK::JobProduct jobProduct;
        if(!AssetBuilderSDK::OutputObject(imageAsset.get(), outputPath, azrtti_typeid<ImageAsset>(), 2, jobProduct))
        {
            AZ_Error(AssetBuilderSDK::ErrorWindow, false, "Failed to output product dependencies.");
            return;
        }
        
        response.m_outputProducts.push_back(jobProduct);
        response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Success;
        AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "Completed gradient image conversion job for %s.\nSucceeded saving output file %s.\n", request.m_fullPath.data(), outputPath.data());
    }