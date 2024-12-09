static int32_t GenerateCookieCallback([[maybe_unused]] SSL* sslSocket, uint8_t* cookieData, uint32_t* cookieLength)
    {
        const AZ::TimeMs currentTime = AZ::GetElapsedTimeMs();

        if ((currentTime - g_lastCookieTimestamp) > net_RotateCookieTimer)
        {
            uint64_t newCookie = CryptoRand64();

            g_cookieReplaceIndex = (g_cookieReplaceIndex + 1) % MaxCookieHistory;
            g_validCookieArray[g_cookieReplaceIndex] = newCookie;
            g_lastCookieTimestamp = currentTime;
        }

        if (cookieLength != nullptr)
        {
            *cookieLength = sizeof(g_validCookieArray[g_cookieReplaceIndex]);
        }

        if (cookieData != nullptr)
        {
            memcpy(cookieData, reinterpret_cast<uint8_t*>(&g_validCookieArray[g_cookieReplaceIndex]), sizeof(g_validCookieArray[g_cookieReplaceIndex]));
        }

        return OpenSslResultSuccess;
    }