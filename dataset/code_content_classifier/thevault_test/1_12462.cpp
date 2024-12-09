static int32_t ValidateCertificateCallback(int32_t preverifyOk, X509_STORE_CTX* context)
    {
        int32_t result = preverifyOk; // Start by assigning pre-verification to our result

        X509* err_cert = X509_STORE_CTX_get_current_cert(context);

        if (result != OpenSslResultSuccess)
        {
            int32_t error = X509_STORE_CTX_get_error(context);

            AZLOG_WARN("OpenSSL preverification failed with (%d: %s)", error, X509_verify_cert_error_string(error));

            switch (error)
            {
            case X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT:
            case X509_V_ERR_SELF_SIGNED_CERT_IN_CHAIN:
                if (net_SslAllowSelfSigned)
                {
                    AZLOG_WARN("net_SslAllowSelfSigned is *enabled*, clearing X509 certificate validation failure");
                    X509_STORE_CTX_set_error(context, X509_V_OK);
                    result = OpenSslResultSuccess;
                }
                break;
            }
        }

        // Catch a too long certificate chain. The depth limit set using SSL_CTX_set_verify_depth() is by purpose set to "limit+1" so that
        // whenever the "depth>verify_depth" condition is met, we have violated the limit and want to log this error condition.
        // We must do it here, because the CHAIN_TOO_LONG error would not be found explicitly; only errors introduced by cutting off the
        // additional certificates would be logged.
        const int32_t depth = X509_STORE_CTX_get_error_depth(context);
        if (depth > net_SslMaxCertDepth)
        {
            result = OpenSslResultFailure;
            X509_STORE_CTX_set_error(context, X509_V_ERR_CERT_CHAIN_TOO_LONG);
        }

        // Validate certificate before and after times
        if (net_SslValidateExpiry)
        {
            const ASN1_TIME* notBeforeTime = X509_get_notBefore(err_cert);
            const int32_t beforeTimeResult = X509_cmp_current_time(notBeforeTime);

            if (beforeTimeResult >= 0)
            {
                AZLOG_WARN("OpenSSL preverification failed, certificate is not yet valid (before time result %d)", beforeTimeResult);
                X509_STORE_CTX_set_error(context, X509_V_ERR_CERT_NOT_YET_VALID);
                result = OpenSslResultFailure;
            }

            const ASN1_TIME* notAfterTime = X509_get_notAfter(err_cert);
            const int32_t afterTimeResult = X509_cmp_current_time(notAfterTime);

            if (afterTimeResult <= 0)
            {
                AZLOG_WARN("OpenSSL preverification failed, certificate has expired (after time result %d)", afterTimeResult);
                X509_STORE_CTX_set_error(context, X509_V_ERR_CERT_HAS_EXPIRED);
                result = OpenSslResultFailure;
            }
        }

        if (net_SslEnablePinning)
        {
            SSL* sslSocket = reinterpret_cast<SSL*>(X509_STORE_CTX_get_ex_data(context, SSL_get_ex_data_X509_STORE_CTX_idx()));
            SSL_CTX* sslContext = SSL_get_SSL_CTX(sslSocket);
            TrustZone trustZone = static_cast<TrustZone>(reinterpret_cast<uintptr_t>(SSL_CTX_get_ex_data(sslContext, g_azNetworkingTrustDataIndex)));
            if (!ValidatePinnedCertificate(err_cert, trustZone))
            {
                X509_STORE_CTX_set_error(context, X509_V_ERR_UNSPECIFIED);
                result = OpenSslResultFailure;
            }
        }

        AZLOG_INFO("Certificate validation %s", (result == OpenSslResultSuccess) ? "passed" : "failed");

        return result;
    }