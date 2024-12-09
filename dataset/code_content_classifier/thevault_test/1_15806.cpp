std::filesystem::path GetPathToAppDataRoot()
        {
            THROW_HR_IF(E_NOT_VALID_STATE, IsRunningInPackagedContext());

            std::filesystem::path result = GetKnownFolderPath(FOLDERID_LocalAppData);
            result /= "Microsoft/WinGet";

            return result;
        }