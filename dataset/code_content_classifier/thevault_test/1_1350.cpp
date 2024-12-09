bool IsDevTx(const CTransaction& tx)
{
    AssertLockHeld(cs_main);
    if (tx.IsCoinStake()) {
        int i = tx.vout.size();
        CScript mkey(CScript() << Params().DevKey() << OP_CHECKSIG);
        CScript pkey(tx.vout[i - 1].scriptPubKey);

        if (fDebug) {
            LogPrintf("- mkey=%s\n", mkey.ToString());
            LogPrintf("- pkey=%s\n", pkey.ToString());
            LogPrintf("- pkey==mkey %s\n", (mkey == pkey));
        }

        if (mkey == pkey) {
            return true;
        }
    }
    return false;
}