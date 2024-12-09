std::filesystem::path GetPathToUserTemp()
        {
            wchar_t tempPath[MAX_PATH + 1];
            DWORD tempChars = GetTempPathW(ARRAYSIZE(tempPath), tempPath);
            THROW_LAST_ERROR_IF(!tempChars);
            THROW_HR_IF(E_UNEXPECTED, tempChars > ARRAYSIZE(tempPath));
            return { std::wstring_view{ tempPath, static_cast<size_t>(tempChars) } };
        }