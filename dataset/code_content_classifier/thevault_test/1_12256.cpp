static AZStd::string DiscoverFullPath(AZStd::string_view normalizedRelativePath, AZStd::string_view currentFolderPath, const AZStd::vector<AZStd::string>& includeDirectories)
        {
            AZStd::string fullPath;
            AzFramework::StringFunc::Path::Join(currentFolderPath.data(), normalizedRelativePath.data(), fullPath);
            if (AZ::IO::SystemFile::Exists(fullPath.c_str()))
            {
                return fullPath;
            }

            for (const auto &includeDir : includeDirectories)
            {
                AzFramework::StringFunc::Path::Join(includeDir.c_str(), normalizedRelativePath.data(), fullPath);
                if (AZ::IO::SystemFile::Exists(fullPath.c_str()))
                {
                    return fullPath;
                }
            }

            return "";
        }