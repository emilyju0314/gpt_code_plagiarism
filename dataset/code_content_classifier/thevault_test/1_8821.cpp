bool CWallet::AddZKey(const libsnowgem::SpendingKey &key)
{
    AssertLockHeld(cs_wallet); // mapZKeyMetadata
    auto addr = key.address();

    if (!CCryptoKeyStore::AddSpendingKey(key))
        return false;

    if (!fFileBacked)
        return true;

    if (!IsCrypted()) {
        return CWalletDB(strWalletFile).WriteZKey(addr,
                                                  key,
                                                  mapZKeyMetadata[addr]);
    }
    return true;
}