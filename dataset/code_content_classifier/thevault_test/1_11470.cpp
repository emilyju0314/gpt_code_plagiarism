std::string CSFTP::getExtensionName(int index)
    {
        std::string extentionName;
        const char *name;
        name = sftp_extensions_get_name(m_sftp, index);
        if (name == NULL)
        {
            throw Exception(*this, __func__);
        }
        extentionName.assign(&name[0], &name[std::strlen(name)]);
        return (extentionName);
    }