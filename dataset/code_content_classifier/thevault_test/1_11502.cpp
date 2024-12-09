bool verifyKnownServer(CSSHSession &sshSession, ServerVerificationContext &verificationContext)
    {
        std::vector<unsigned char> keyHash;
        CSSHSession::Key serverPublicKey;
        int returnCode;
        returnCode = sshSession.isServerKnown();
        serverPublicKey = sshSession.getPublicKey();
        sshSession.getPublicKeyHash(serverPublicKey, keyHash);
        switch (returnCode)
        {
        case SSH_SERVER_KNOWN_OK:
            verificationContext.serverKnown();
            break;
        case SSH_SERVER_KNOWN_CHANGED:
            return (verificationContext.serverKnownChanged(keyHash));
        case SSH_SERVER_FOUND_OTHER:
            return (verificationContext.serverFoundOther());
        case SSH_SERVER_FILE_NOT_FOUND:
            return (verificationContext.serverFileNotFound(keyHash));
        case SSH_SERVER_NOT_KNOWN:
            return (verificationContext.serverNotKnown(keyHash));
        case SSH_SERVER_ERROR:
            return (verificationContext.serverError());
        }
        return (true);
    }