std::string CSFTP::getExtensionData(int index)
    {
        std::string extensionData;
        const char *data;
        data = sftp_extensions_get_data(m_sftp, index);
        if (data == NULL)
        {
            throw Exception(*this, __func__);
        }
        extensionData.assign(&data[0], &data[std::strlen(data)]);
        return (extensionData);
    }