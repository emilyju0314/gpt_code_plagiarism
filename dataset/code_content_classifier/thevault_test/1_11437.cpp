std::string CSSHSession::convertKeyHashToHex(std::vector<unsigned char> &keyHash)
    {
        char *hexa = NULL;
        std::string convertedHash;
        hexa = ssh_get_hexa(&keyHash[0], keyHash.size());
        if (hexa != NULL)
        {
            convertedHash.assign(&hexa[0], &hexa[std::strlen(hexa)]);
            ssh_string_free_char(hexa);
        }
        return (convertedHash);
    }