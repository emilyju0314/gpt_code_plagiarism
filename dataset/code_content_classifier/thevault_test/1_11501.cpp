bool userAuthorize(CSSHSession &session)
    {
        int authorizationMethod;
        if (session.userAuthorizationNone() == SSH_AUTH_SUCCESS)
        {
            return (true);
        }
        authorizationMethod = session.userAuthorizationList();
        if (authorizationMethod & SSH_AUTH_METHOD_NONE)
        {
            if (session.userAuthorizationNone() == SSH_AUTH_SUCCESS)
            {
                return (true);
            }
        }
        if (authorizationMethod & SSH_AUTH_METHOD_PUBLICKEY)
        {
            if (session.userAuthorizationWithPublicKeyAuto() == SSH_AUTH_SUCCESS)
            {
                return (true);
            }
        }
        if (authorizationMethod & SSH_AUTH_METHOD_INTERACTIVE)
        {
            if (session.userAuthorizationWithKeyboardInteractive() == SSH_AUTH_SUCCESS)
            {
                return (true);
            }
        }
        if (authorizationMethod & SSH_AUTH_METHOD_PASSWORD)
        {
            if (session.userAuthorizationWithPassword() == SSH_AUTH_SUCCESS)
            {
                return (true);
            }
        }
        return (false);
    }