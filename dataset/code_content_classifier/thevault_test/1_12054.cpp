bool MutateToAbsolutePathIfFound(AZStd::string& relativePathToSearch)
            {
                bool found = false;
                if (AzFramework::StringFunc::Path::IsRelative(relativePathToSearch.c_str()))
                {
                    AZ::Data::AssetInfo sourceInfo;
                    AZStd::string watchFolder;
                    AzToolsFramework::AssetSystemRequestBus::BroadcastResult(found,
                                                                             &AzToolsFramework::AssetSystem::AssetSystemRequest::GetSourceInfoBySourcePath,
                                                                             relativePathToSearch.c_str(),
                                                                             sourceInfo,
                                                                             watchFolder);
                    if (found)
                    {
                        AZStd::string absoluteOutput;
                        AzFramework::StringFunc::Path::Join(watchFolder.c_str(), relativePathToSearch.c_str(), absoluteOutput);
                        relativePathToSearch = std::move(absoluteOutput);
                    }
                }
                return found;
            }