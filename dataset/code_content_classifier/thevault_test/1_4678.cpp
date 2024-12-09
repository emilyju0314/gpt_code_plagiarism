inline std::wstring to_wstring(const krabs::guid& guid)
    {
        wchar_t* guidString;
        HRESULT hr = StringFromCLSID(guid, &guidString);

        if (FAILED(hr)) throw std::bad_alloc();

        std::unique_ptr<wchar_t, krabs::CoTaskMemDeleter> managed(guidString);

        return { managed.get() };
    }