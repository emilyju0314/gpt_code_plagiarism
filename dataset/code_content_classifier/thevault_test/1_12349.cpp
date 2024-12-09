AuthenticationTokens::AuthenticationTokens()
    {
        m_tokensExpireTimeStamp = AZStd::chrono::system_clock::time_point::min();
        m_providerName = ProviderNameEnum::None;
    }