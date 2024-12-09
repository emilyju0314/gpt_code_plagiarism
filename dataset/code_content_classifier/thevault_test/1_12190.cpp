void AddPossibleDependencies(AZStd::string_view currentFilePath,
            AZStd::string_view referencedParentPath,
            const char* jobKey,
            AZStd::vector<AssetBuilderSDK::JobDependency>& jobDependencies,
            bool isOrderedOnceForMaterialTypes = false)
        {
            bool dependencyFileFound = false;

            AZStd::vector<AZStd::string> possibleDependencies = RPI::AssetUtils::GetPossibleDepenencyPaths(currentFilePath, referencedParentPath);
            for (auto& file : possibleDependencies)
            {
                // The first path found is the highest priority, and will have a job dependency, as this is the one
                // the builder will actually use
                if (!dependencyFileFound)
                {
                    AZ::Data::AssetInfo sourceInfo;
                    AZStd::string watchFolder;
                    AzToolsFramework::AssetSystemRequestBus::BroadcastResult(dependencyFileFound, &AzToolsFramework::AssetSystem::AssetSystemRequest::GetSourceInfoBySourcePath, file.c_str(), sourceInfo, watchFolder);

                    if (dependencyFileFound)
                    {
                        AssetBuilderSDK::JobDependency jobDependency;
                        jobDependency.m_jobKey = jobKey;
                        jobDependency.m_sourceFile.m_sourceFileDependencyPath = file;

                        const bool isMaterialTypeFile = AzFramework::StringFunc::Path::IsExtension(file.c_str(), MaterialTypeSourceData::Extension);
                        jobDependency.m_type = (isMaterialTypeFile && isOrderedOnceForMaterialTypes) ? AssetBuilderSDK::JobDependencyType::OrderOnce : AssetBuilderSDK::JobDependencyType::Order;

                        jobDependencies.push_back(jobDependency);
                    }
                }
            }
        }