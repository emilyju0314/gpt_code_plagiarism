static void AppendListOfPossibleFutureLocations(AZStd::unordered_set<AZStd::string>& includedFiles, AZStd::string_view normalizedRelativePath, AZStd::string_view currentFolderPath, const AZStd::vector<AZStd::string>& includeDirectories)
        {
            AZStd::string fullPath;
            AzFramework::StringFunc::Path::Join(currentFolderPath.data(), normalizedRelativePath.data(), fullPath);
            includedFiles.insert(fullPath);
            for (const auto &includeDir : includeDirectories)
            {
                AzFramework::StringFunc::Path::Join(includeDir.c_str(), normalizedRelativePath.data(), fullPath);
                includedFiles.insert(fullPath);
            }
        }