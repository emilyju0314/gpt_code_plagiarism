inline std::string to_string(const GUID& guid)
    {
        char guid_string[37]; // 32 hex chars + 4 hyphens + null terminator
        snprintf(
            guid_string, sizeof(guid_string),
            "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
            guid.Data1, guid.Data2, guid.Data3,
            guid.Data4[0], guid.Data4[1], guid.Data4[2],
            guid.Data4[3], guid.Data4[4], guid.Data4[5],
            guid.Data4[6], guid.Data4[7]);
        return guid_string;
    }