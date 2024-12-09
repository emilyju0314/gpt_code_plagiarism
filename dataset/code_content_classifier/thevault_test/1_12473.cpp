void InitializePreprocessorOptions(
            PreprocessorOptions& options, [[maybe_unused]] const char* builderName, const char* optionalIncludeFolder)
        {
            AZ_TraceContext("Init include-paths lookup options", "preprocessor");

            // get the scan folders of the projects:
            bool success = true;
            AZStd::vector<AZStd::string> scanFoldersVector;
            AzToolsFramework::AssetSystemRequestBus::BroadcastResult(success,
                &AzToolsFramework::AssetSystemRequestBus::Events::GetScanFolders,
                scanFoldersVector);
            AZ_Warning(builderName, success, "Preprocessor option: Could not acquire a list of scan folders from the database.");

            // Add the project path to list of include paths
            AZ::IO::FixedMaxPath projectPath = AZ::Utils::GetProjectPath();
            auto FindPath = [](AZ::IO::PathView searchPath)
            {
                return [searchPath](AZStd::string_view includePathView)
                {
                    return searchPath == AZ::IO::PathView(includePathView);
                };
            };
            if (auto it = AZStd::find_if(options.m_projectIncludePaths.begin(), options.m_projectIncludePaths.end(), FindPath(projectPath));
                it == options.m_projectIncludePaths.end())
            {
                options.m_projectIncludePaths.emplace_back(projectPath.c_str(), projectPath.Native().size());
            }
            if (optionalIncludeFolder)
            {
                if (auto it = AZStd::find_if(options.m_projectIncludePaths.begin(), options.m_projectIncludePaths.end(), FindPath(optionalIncludeFolder));
                    it == options.m_projectIncludePaths.end())
                {
                    if (AZ::IO::SystemFile::Exists(optionalIncludeFolder))
                    {
                        options.m_projectIncludePaths.emplace_back(AZStd::move(AZ::IO::Path(optionalIncludeFolder).LexicallyNormal().Native()));
                    }
                }
            }
            // but while we transfer to the set, we're going to keep only folders where +/ShaderLib exists
            for (AZ::IO::Path shaderScanFolder : scanFoldersVector)
            {
                shaderScanFolder /= "ShaderLib";
                if (auto it = AZStd::find_if(options.m_projectIncludePaths.begin(), options.m_projectIncludePaths.end(), FindPath(shaderScanFolder));
                    it == options.m_projectIncludePaths.end())
                {
                    // the folders constructed this fashion constitute the base of automatic include search paths
                    if (AZ::IO::SystemFile::Exists(shaderScanFolder.c_str()))
                    {
                        options.m_projectIncludePaths.emplace_back(AZStd::move(shaderScanFolder.LexicallyNormal().Native()));
                    }
                }
            }

            // finally the <engineroot>/Gems fallback
            AZ::IO::Path engineGemsFolder(AZStd::string_view{ AZ::Utils::GetEnginePath() });
            engineGemsFolder /= "Gems";
            if (auto it = AZStd::find_if(options.m_projectIncludePaths.begin(), options.m_projectIncludePaths.end(), FindPath(engineGemsFolder));
                it == options.m_projectIncludePaths.end())
            {
                if (AZ::IO::SystemFile::Exists(engineGemsFolder.c_str()))
                {
                    options.m_projectIncludePaths.emplace_back(AZStd::move(engineGemsFolder.Native()));
                }
            }
        }