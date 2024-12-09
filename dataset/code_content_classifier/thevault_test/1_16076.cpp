Value fetchbalance(const Array& params, bool fHelp)
{
    if (fHelp || params.size() != 0)
        throw runtime_error(
            "fetchbalance\n"
            "Returns an object containing various wallet balance info.");
    Object obj, watchonly;
    obj.push_back(Pair("totalbalance",  ValueFromAmount(pwalletMain->GetBalance())));
    obj.push_back(Pair("anonbalance",   ValueFromAmount(pwalletMain->GetAnonBalance())));
    obj.push_back(Pair("locked",        ValueFromAmount(pwalletMain->GetLockedBalance())));
    obj.push_back(Pair("unlocked",      ValueFromAmount(pwalletMain->GetUnlockedBalance())));
    obj.push_back(Pair("newmint",       ValueFromAmount(pwalletMain->GetNewMint())));
    obj.push_back(Pair("stake",         ValueFromAmount(pwalletMain->GetStake())));
    obj.push_back(Pair("stakeable",     ValueFromAmount(pwalletMain->GetStakeAmount())));
    obj.push_back(Pair("immature",      ValueFromAmount(pwalletMain->GetImmatureBalance())));
    obj.push_back(Pair("unconfirmed",   ValueFromAmount(pwalletMain->GetUnconfirmedBalance())));

    watchonly.push_back(Pair("balance",     ValueFromAmount(pwalletMain->GetWatchOnlyBalance())));
    watchonly.push_back(Pair("unconfirmed", ValueFromAmount(pwalletMain->GetUnconfirmedWatchOnlyBalance())));
    watchonly.push_back(Pair("immature",     ValueFromAmount(pwalletMain->GetImmatureWatchOnlyBalance())));
    obj.push_back(Pair("watchonly",    watchonly));

    return obj;
}