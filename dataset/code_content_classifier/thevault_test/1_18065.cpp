void LegacyScriptPubKeyMan::UpdateTimeFirstKey(int64_t nCreateTime)
{
    AssertLockHeld(cs_KeyStore);
    if (nCreateTime <= 1) {
        // Cannot determine birthday information, so set the wallet birthday to
        // the beginning of time.
        nTimeFirstKey = 1;
    } else if (!nTimeFirstKey || nCreateTime < nTimeFirstKey) {
        nTimeFirstKey = nCreateTime;
    }
}