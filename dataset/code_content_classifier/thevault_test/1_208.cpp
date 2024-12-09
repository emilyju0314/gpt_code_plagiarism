int VerifyCallback(int ok, X509_STORE_CTX *ctx)
    {
        // If we encounter an expired cert error (which is fine) or a critical extension (most MS
        // certs contain MS-specific extensions that OpenSSL doesn't know how to evaluate), 
        // just return success
        if (!ok && (ctx->error == X509_V_ERR_CERT_HAS_EXPIRED || 
                    ctx->error == X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION))
        {
            ok = static_cast<int>(true);
        }
        return ok; 
    }