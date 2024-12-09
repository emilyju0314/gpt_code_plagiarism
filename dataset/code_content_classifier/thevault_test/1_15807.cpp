std::filesystem::path GetUserSID()
        {
            auto userToken = wil::get_token_information<TOKEN_USER>();

            wil::unique_hlocal_string sidString;
            THROW_IF_WIN32_BOOL_FALSE(ConvertSidToStringSidW(userToken->User.Sid, &sidString));
            return { sidString.get() };
        }