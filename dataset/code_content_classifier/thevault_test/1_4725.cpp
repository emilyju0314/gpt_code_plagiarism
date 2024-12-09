inline std::string from_wstring(const std::wstring& wstr, UINT codePage = CP_UTF8)
    {
        if (wstr.empty())
            return {};

        const auto requiredLen = WideCharToMultiByte(codePage, 0, wstr.data(), static_cast<int>(wstr.size()), 
            nullptr, 0, nullptr, nullptr);
        if (0 == requiredLen)
            return {};

        std::string result(requiredLen, 0);
        const auto convertedLen = WideCharToMultiByte(codePage, 0, wstr.data(), static_cast<int>(wstr.size()),
            &result[0], requiredLen, nullptr, nullptr);
        if (0 == convertedLen)
            return {};

        return result;
    }