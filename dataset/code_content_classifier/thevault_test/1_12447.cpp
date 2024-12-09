void TranslationBuilderWorker::ProcessJob(const AssetBuilderSDK::ProcessJobRequest& request, AssetBuilderSDK::ProcessJobResponse& response) const
    {
        // Here's an example of listening for cancellation requests.  You should listen for cancellation requests and then cancel work if possible.
        //You can always derive from the Job Cancel Listener and reimplement Cancel() if you need to do more things such as signal a semaphore or other threading work.

        AssetBuilderSDK::JobCancelListener jobCancelListener(request.m_jobId);
        AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "Starting Job.");
        AZStd::string fileName;

        AzFramework::StringFunc::Path::GetFullFileName(request.m_fullPath.c_str(), fileName);
        AzFramework::StringFunc::Path::ReplaceExtension(fileName, "qm");

        AZStd::string destPath;

        // you should do all your work inside the tempDirPath.
        // don't write outside this path
        AzFramework::StringFunc::Path::ConstructFull(request.m_tempDirPath.c_str(), fileName.c_str(), destPath, true);

        // use AZ_TracePrintF to communicate job details.  The logging system will automatically file the text under the appropriate log file and category.

        if (!m_isShuttingDown && !jobCancelListener.IsCancelled())
        {
            AZStd::string lRelease( FindLReleaseTool() );

            if( lRelease.empty() )
            {
                AZ_Error(AssetBuilderSDK::ErrorWindow, false, "Can't find the Qt \"lrelease\" tool!");
                response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Failed;
                return;
            }
            else
            {
                AzFramework::ProcessLauncher::ProcessLaunchInfo processLaunchInfo;
                AZStd::string command( AZStd::string::format("\"%s\" \"%s\" -qm \"%s\"", lRelease.c_str(), request.m_fullPath.c_str(), destPath.c_str()) );

                AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "Issuing command:%s", command.c_str());

                processLaunchInfo.m_commandlineParameters = command;
                processLaunchInfo.m_showWindow = false;
                processLaunchInfo.m_workingDirectory = request.m_tempDirPath;
                processLaunchInfo.m_processPriority = AzFramework::ProcessPriority::PROCESSPRIORITY_IDLE;

                AzFramework::ProcessWatcher* watcher = AzFramework::ProcessWatcher::LaunchProcess(processLaunchInfo, AzFramework::ProcessCommunicationType::COMMUNICATOR_TYPE_STDINOUT);

                if (!watcher)
                {
                    AZ_Error(AssetBuilderSDK::ErrorWindow, false, "Error while processing job %s.", request.m_fullPath.c_str());
                    response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Failed;
                    return;
                }
                AZ::u32 exitCode = 0;
                bool result = watcher->WaitForProcessToExit(300);
                if (result)
                {
                    // grab output and append to logs, will help with any debugging down the road.
                    AzFramework::ProcessCommunicator* processCommunicator = watcher->GetCommunicator();
                    if ( processCommunicator && processCommunicator->IsValid() )
                    {
                        AzFramework::ProcessOutput rawOutput;
                        processCommunicator->ReadIntoProcessOutput(rawOutput);

                        // note that the rawOutput may contain a formating code, such as "%s" within the text,
                        // so we need make sure that use the "%s" in the AZ_TracePrintf below.

                        if( rawOutput.HasError() )
                        {
                            AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "%s", rawOutput.errorResult.c_str());
                        }

                        if( rawOutput.HasOutput() )
                        {
                            AZ_TracePrintf(AssetBuilderSDK::InfoWindow, "%s", rawOutput.outputResult.c_str());
                        }
                    }

#if AZ_TRAIT_LMBRCENTRAL_TRANSLATION_BUILDER_SHOULD_CHECK_QT_PROCESS
                    // the process ran, but was it successful in its run?
                    bool wasRunning = watcher->IsProcessRunning(&exitCode);
#else
                    bool wasRunning = false;
#endif
                    if( !wasRunning && (exitCode == 0) )
                    {
                        // if you succeed in building assets into your temp dir, you should push them back into the response's product list
                        // Assets you created in your temp path can be specified using paths relative to the temp path, since that is assumed where you're writing stuff.
                        AZStd::string relPath = destPath;
                        response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Success;

                        AssetBuilderSDK::JobProduct jobProduct(fileName);
                        jobProduct.m_dependenciesHandled = true; // This builder has no product dependencies
                        response.m_outputProducts.push_back(jobProduct);
                    }
                    else
                    {
                        AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "The process failed, exit code %u, while processing job %s.", exitCode, request.m_fullPath.c_str());
                        response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Failed;
                    }
                }
                else
                {
                    AZ_Error(AssetBuilderSDK::ErrorWindow, false, "Process timed out while processing job %s.", request.m_fullPath.c_str());
                    response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Failed;
                }
            }
        }
        else
        {
            if (m_isShuttingDown)
            {
                AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Cancelled job %s because shutdown was requested", request.m_fullPath.c_str());
                response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
            }
            else if (jobCancelListener.IsCancelled())
            {
                AZ_TracePrintf(AssetBuilderSDK::ErrorWindow, "Cancelled was requested for job %s", request.m_fullPath.c_str());
                response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Cancelled;
            }
            else
            {
                AZ_Error(AssetBuilderSDK::ErrorWindow, false, "Error while processing job %s.", request.m_fullPath.c_str());
                response.m_resultCode = AssetBuilderSDK::ProcessJobResult_Failed;
            }
        }
    }