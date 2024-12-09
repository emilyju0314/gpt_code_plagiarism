bool X509Cert::Write()
    {
        /* Check for null data. */
        if(!pkey)
            return debug::error(FUNCTION, "Unitialized EVP_PKEY");
        if(!px509)
            return debug::error(FUNCTION, "Uninitialized certificate.");

        /* Identify the ssl subfolder. */
        std::string strFolder = config::GetDataDir() + "ssl/";

        /* Create the ssl subfolder if it doesn't exist. */
        if(!filesystem::exists(strFolder))
            filesystem::create_directory(strFolder);

        /* Identify the certificate and key paths. */
        std::string strKeyPath = strFolder + "key.pem";
        std::string strCertPath = strFolder + "cert.pem";

        /* Write the private key PEM file to the key path. */
        FILE *pFile = fopen(strKeyPath.c_str(), "wb");
        if(!pFile)
            return debug::error(FUNCTION, "X509Cert : Unable to open key file.");
        bool ret = PEM_write_PrivateKey(pFile, pkey, nullptr, nullptr, 0, nullptr, nullptr);
        fclose(pFile);
        if(!ret)
            return debug::error(FUNCTION, "X509Cert : Unable to write key file.");

        /* Write the certificate PEM file to the certificate path. */
        pFile = fopen(strCertPath.c_str(), "wb");
        if(!pFile)
            return debug::error(FUNCTION, "X509Cert : Unable to open cert file.");
        ret = PEM_write_X509(pFile, px509);
        fclose(pFile);
        if(!ret)
            return debug::error(FUNCTION, "X509Cert : Unable to write cert file.");

        return true;
    }