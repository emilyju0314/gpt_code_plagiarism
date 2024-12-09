bool X509Cert::Init_SSL(SSL *ssl)
    {
        /* Check for null data. */
        if(ssl == nullptr)
            return debug::error(FUNCTION, "SSL object is null.");
        if(px509 == nullptr)
            return debug::error(FUNCTION, "certificate is null.");
        if(pkey == nullptr)
            return debug::error(FUNCTION, "private key is null.");

        /* Assign the certiicate to the SSL object. */
        if(SSL_use_certificate(ssl, px509) != 1)
            return debug::error(FUNCTION, "Failed to initialize SSL with certificate.");

        /* Assign the private key to the SSL object. */
        if(SSL_use_PrivateKey(ssl, pkey) != 1)
            return debug::error(FUNCTION, "Failed to initialize SSL with private key.");

        return true;
    }