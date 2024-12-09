bool ECKey::IsValid() const
    {
        if(!fSet)
            return false;

        bool fCompr = false;
        CSecret secret = GetSecret(fCompr);
        ECKey key2;
        key2.SetSecret(secret, fCompr);
        return GetPubKey() == key2.GetPubKey();
    }