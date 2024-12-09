static int32_t VerifyCookieCallback([[maybe_unused]] SSL* sslSocket, const uint8_t* cookieData, uint32_t cookieLength)
    {
        if (cookieLength != sizeof(uint64_t))
        {
            // This should be logged somehow, but since this is part of DOS prevention I don't think I should *ACTUALLY* log here..
            return OpenSslResultFailure;
        }

        uint64_t cookie = *reinterpret_cast<const uint64_t*>(cookieData);

        for (uint32_t i = 0; i < MaxCookieHistory; ++i)
        {
            if (g_validCookieArray[i] == cookie)
            {
                return OpenSslResultSuccess;
            }
        }

        // This should be logged somehow, but since this is part of DOS prevention I don't think I should *ACTUALLY* log here..
        return OpenSslResultFailure;
    }