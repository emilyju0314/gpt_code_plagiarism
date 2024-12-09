void ExampleBuilderWorker::ProcessJob(const AssetBuilderSDK::ProcessJobRequest& request, AssetBuilderSDK::ProcessJobResponse& response)
    {
        // This is the most basic example of handling for cancellation requests.
        // If possible, you should listen for cancellation requests and then cancel processing work to facilitate faster shutdown of the Asset Processor
        // If you need to do more things such as signal a semaphore or other threading work, derive from the Job Cancel Listener and reimplement Cancel()
        AssetBuilderSDK::JobCancelListener jobCancelListener(request.m_jobId);

        // Use AZ_TracePrintf to communicate job details. The logging system will automatically file the text under the appropriate log file and category.
        AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "Starting Job.\n");

        AZStd::string fileName;
        AzFramework::StringFunc::Path::GetFullFileName(request.m_fullPath.c_str(), fileName);
        AZStd::string ext;
        AzFramework::StringFunc::Path::GetExtension(request.m_sourceFile.c_str(), ext, false);

        if (AzFramework::StringFunc::Equal(ext.c_str(), "example"))
        {
            if (AzFramework::StringFunc::Equal(request.m_jobDescription.m_jobKey.c_str(), "Compile Example"))
            {
                AzFramework::StringFunc::Path::ReplaceExtension(fileName, "example1");
            }
            else if (AzFramework::StringFunc::Equal(request.m_jobDescription.m_jobKey.c_str(), "Second Compile Example"))
            {
                AzFramework::StringFunc::Path::ReplaceExtension(fileName, "example2");
            }
        }
        else if (AzFramework::StringFunc::Equal(ext.c_str(), "examplesource"))
        {
            AzFramework::StringFunc::Path::ReplaceExtension(fileName, "examplesourceprocessed");
        }
        else if (AzFramework::StringFunc::Equal(ext.c_str(), "examplejob"))
        {
            AzFramework::StringFunc::Path::ReplaceExtension(fileName, "examplejobprocessed");
        }

        // All your work should happen inside the tempDirPath.
        // The Asset Processor will handle taking the completed files you specify in JobProduct.m_outputProducts from the temp directory into the cache.
        AZStd::string destPath;
        AzFramework::StringFunc::Path::ConstructFull(request.m_tempDirPath.c_str(), fileName.c_str(), destPath, true);

        // Check if we are cancelled or shutting down before doing intensive processing on this source file
        if (jobCancelListener.IsCancelled())
        {
            AZ_TracePrintf(AssetBuilderSDK::WarningWindow, "Cancel was requested for job %s.\n", request.m_fullPath.c_str());
            response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
            return;
        }
        if (m_isShuttingDown)
        {
            AZ_TracePrintf(AssetBuilderSDK::WarningWindow, "Cancelled job %s because shutdown was requested.\n", request.m_fullPath.c_str());
            response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
            return;
        }

        AZ::IO::LocalFileIO fileIO;
        if (fileIO.Copy(request.m_fullPath.c_str(), destPath.c_str()) != AZ::IO::ResultCode::Success)
        {
            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Error during processing job %s.\n", request.m_fullPath.c_str());
            response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Failed;
            return;
        }

        // Push all products successfully built into the JobProduct.m_outputProducts.
        // Filepaths can be absolute, or relative to your temporary directory.
        // The job request struct has the temp directory, so it will be properly reconstructed to an absolute path later.
        AssetBuilderSDK::JobProduct jobProduct(fileName);

        // Note - you must also add the asset type to the JobProduct.
        // If you have direct access to the type within your gem, you can grab the asset type directly:
        //     jobProduct.m_productAssetType = return AZ::AzTypeInfo<CustomAssetExample>::Uuid();
        // If you need to cross a gem boundary, you can use the AssetTypeInfo EBus and EBusFindAssetTypeByName:
        //     EBusFindAssetTypeByName assetType("customassetexample");
        //     AssetTypeInfoBus::BroadcastResult(assetType, &AssetTypeInfo::GetAssetType);
        //     jobProduct.m_productAssetType = assetType.GetAssetType();

        // You should also pick a unique "SubID" for each product.  The final address of an asset (the AssetId) is the combination
        // of the subId you choose here and the source file's UUID, so if it is not unique, errors will be generated since your
        // assets will shadow each other's address, and not be accessible via AssetId.
        // you can pick whatever scheme you want but you should ensure stablility in your choice.
        // For example, do not use random numbers - ideally no matter what happens, each time you run this process, the same
        // subIds are chosen for the same logical asset (even if your builder starts emitting more or different assets out of the same source)
        // You can use AssetBuilderSDK::ConstructSubID(...) helper function if you want to use various bits of the subID for things like LOD level
        // or you can come up with your own scheme to ensure stability, using the 32-bit address space as you see fit.  It only has to be unique
        // and stable within the confines of a single source file, it is not globally unique.
        jobProduct.m_productSubID = 0;
        
        // once you've filled up the details of the product in jobProduct, add it to the result list:
        response.m_outputProducts.push_back(jobProduct);

        response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Success;
    }