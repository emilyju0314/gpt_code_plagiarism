void ExampleBuilderWorker::CreateJobs(const AssetBuilderSDK::CreateJobsRequest& request, AssetBuilderSDK::CreateJobsResponse& response)
    {
        if (m_isShuttingDown)
        {
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::ShuttingDown;
            return;
        }

        AZStd::string ext;
        AzFramework::StringFunc::Path::GetExtension(request.m_sourceFile.c_str(), ext, false);

        // Our *.example extension details a source file with NO dependencies.
        // Here we simply create the JobDescriptors for each enabled platform in order to process the source file.
        if (AzFramework::StringFunc::Equal(ext.c_str(), "example"))
        {
            for (const AssetBuilderSDK::PlatformInfo& platformInfo : request.m_enabledPlatforms)
            {
                // We create a simple job here which only contains the identifying job key and the platform to process the file on
                AssetBuilderSDK::JobDescriptor descriptor;
                descriptor.m_jobKey = "Compile Example";
                descriptor.SetPlatformIdentifier(platformInfo.m_identifier.c_str());

                // Note that there are additional parameters for the JobDescriptor which may be beneficial in your use case.
                // Notable ones include:
                //   * m_critical - a boolean that flags this job as one which must complete before the Editor will start up.
                //   * m_priority - an integer where larger values signify that the job should be processed with higher priority than those with lower values.
                // Please see the JobDescriptor for the full complement of configuration parameters.
                response.m_createJobOutputs.push_back(descriptor);

                // One builder can make multiple jobs for the same source file, for the same platform, as long as it emits a different job key per job. 
                // This allows you to break large compilations up into smaller jobs.  Jobs emitted in this manner may be run in parallel
                descriptor.m_jobKey = "Second Compile Example";

                // Custom parameters that you may need to know about when the job processes can be added to m_jobParameters
                descriptor.m_jobParameters[AZ_CRC("hello", 0x3610a686)] = "World";
                response.m_createJobOutputs.push_back(descriptor);
            }

            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
            return;
        }

        // Our *.examplesource extension details a source file with dependencies.
        // Here we declare source file dependencies and forward the info to the Asset Processor
        // This example creates the following dependencies:
        //     * the source file .../test.examplesource depends on the source file  .../test.exampleinclude 
        //     * the source file .../test.exampleinclude depends on the source file .../common.exampleinclude
        //     * the source file .../common.exampleinclude depends on the non-source file .../common.examplefile

        // Note - both file extensions "exampleinclude" and "examplesource" are handled by this builder class.
        // However, files with extension "exampleinclude" do not create JobDescriptors, so they are not actually being processed by this builder.
        // We are only collecting their dependencies here.
        AssetBuilderSDK::SourceFileDependency sourceFileDependencyInfo;
        AZStd::string fullPath;
        AzFramework::StringFunc::Path::ConstructFull(request.m_watchFolder.c_str(), request.m_sourceFile.c_str(), fullPath, false);
        AzFramework::StringFunc::Path::Normalize(fullPath);
        AZStd::string relPath = request.m_sourceFile;

        // Source files in this example generate dependencies on a file with the same name, but having "exampleinclude" extensions
        if (AzFramework::StringFunc::Equal(ext.c_str(), "examplesource"))
        {
            AzFramework::StringFunc::Path::ReplaceExtension(relPath, "exampleinclude");
            // Declare and add the dependency on the *.exampleinclude file:
            sourceFileDependencyInfo.m_sourceFileDependencyPath = relPath;
            response.m_sourceFileDependencyList.push_back(sourceFileDependencyInfo);

            // Since we're a source file, we also add a job to do the actual compilation (for each enabled platform)
            for (const AssetBuilderSDK::PlatformInfo& platformInfo : request.m_enabledPlatforms)
            {
                AssetBuilderSDK::JobDescriptor descriptor;
                descriptor.m_jobKey = "Compile Example";
                descriptor.SetPlatformIdentifier(platformInfo.m_identifier.c_str());

                // you can also place whatever parameters you want to save for later into this map:
                descriptor.m_jobParameters[AZ_CRC("hello", 0x3610a686)] = "World";
                response.m_createJobOutputs.push_back(descriptor);
            }

            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
            return;
        }

        if (AzFramework::StringFunc::Equal(ext.c_str(), "exampleinclude"))
        {
            if (AzFramework::StringFunc::Find(request.m_sourceFile.c_str(), "common.exampleinclude") != AZStd::string::npos)
            {
                // Add any dependencies that common.exampleinclude would like to depend on here, we can also add a non source file as a dependency like we are doing here
                AzFramework::StringFunc::Path::ReplaceFullName(fullPath, "common.examplefile");
                sourceFileDependencyInfo.m_sourceFileDependencyPath = fullPath;
            }
            else
            {
                AzFramework::StringFunc::Path::ReplaceFullName(fullPath, "common.exampleinclude");
                // Assigning full path to sourceFileDependency path
                sourceFileDependencyInfo.m_sourceFileDependencyPath = fullPath;
            }

            response.m_sourceFileDependencyList.push_back(sourceFileDependencyInfo);
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
            return;
        }
        // This example shows how you would be able to declare job dependencies on source files inside a builder and
        // forward that info to the asset processor.
        // Basically here we are creating a job dependency such that the job with source file ./test.examplejob and 
        // jobKey "Compile Example" depends on the fingerprint of the job with source file ./test.examplesource and jobkey "Compile Example". 

        else if (AzFramework::StringFunc::Equal(ext.c_str(), "examplejob"))
        {
            for (const AssetBuilderSDK::PlatformInfo& platformInfo : request.m_enabledPlatforms)
            {
                AssetBuilderSDK::JobDescriptor descriptor;
                descriptor.m_jobKey = "Compile Example";
                descriptor.SetPlatformIdentifier(platformInfo.m_identifier.c_str());
                AssetBuilderSDK::SourceFileDependency sourceFile;
                sourceFile.m_sourceFileDependencyPath = "test.examplesource";
                AssetBuilderSDK::JobDependency jobDependency("Compile Example", platformInfo.m_identifier.c_str(), AssetBuilderSDK::JobDependencyType::Fingerprint, sourceFile);
                descriptor.m_jobDependencyList.push_back(jobDependency);
                response.m_createJobOutputs.push_back(descriptor);
            }
            response.m_result = AssetBuilderSDK::CreateJobsResultCode::Success;
            return;
        }

        AZ_Assert(false, "Unhandled extension type in CustomExampleAssetBuilderWorker.");
        response.m_result = AssetBuilderSDK::CreateJobsResultCode::Failed;
    }