static void GetListOfIncludedFiles(AZStd::string_view sourceFilePath, const AZStd::vector<AZStd::string>& includeDirectories,
            const ShaderBuilderUtility::IncludedFilesParser& includedFilesParser, AZStd::unordered_set<AZStd::string>& includedFiles)
        {
            auto outcome = includedFilesParser.ParseFileAndGetIncludedFiles(sourceFilePath);
            if (!outcome.IsSuccess())
            {
                AZ_Warning(ShaderAssetBuilderName, false, outcome.GetError().c_str());
                return;
            }

            // Cache the path of the folder where @sourceFilePath is located.
            AZStd::string sourceFileFolderPath;
            {
                AZStd::string drive;
                AzFramework::StringFunc::Path::Split(sourceFilePath.data(), &drive, &sourceFileFolderPath);
                if (!drive.empty())
                {
                    AzFramework::StringFunc::Path::Join(drive.c_str(), sourceFileFolderPath.c_str(), sourceFileFolderPath);
                }
            }

            auto listOfRelativePaths = outcome.TakeValue();
            for (auto relativePath : listOfRelativePaths)
            {
                auto fullPath = DiscoverFullPath(relativePath, sourceFileFolderPath, includeDirectories);
                if (fullPath.empty())
                {
                    // The file doesn't exist in any of the includeDirectories. It doesn't exist in @sourceFileFolderPath either.
                    // The file may appear in the future in one of those directories, We must build an exhaustive list
                    // of full file paths where the file may appear in the future.
                    AppendListOfPossibleFutureLocations(includedFiles, relativePath, sourceFileFolderPath, includeDirectories);
                    continue;
                }

                // Add the file to the list and keep parsing recursively.
                if (includedFiles.count(fullPath))
                {
                    continue;
                }
                includedFiles.insert(fullPath);
                GetListOfIncludedFiles(fullPath, includeDirectories, includedFilesParser, includedFiles);
            }
        }