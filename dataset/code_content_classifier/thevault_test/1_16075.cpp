Value walletstatus(const Array& params, bool fHelp)
{
	if (fHelp || params.size() != 0)
        throw runtime_error(
            "walletstatus\n"
			"Returns the current wallet lock and encryption status.");

	Object obj;
    if (pwalletMain->IsCrypted())
        obj.push_back(Pair("unlocked_until", (int64_t)nWalletUnlockTime / 1000));
	if (!pwalletMain->IsCrypted())
        obj.push_back(Pair("wallet_status", "unencrypted"));
	if (!pwalletMain->IsLocked() && pwalletMain->IsCrypted() && !fWalletUnlockStakingOnly)
		obj.push_back(Pair("wallet_status", "unlocked"));
	if (!pwalletMain->IsLocked() && pwalletMain->IsCrypted() && fWalletUnlockStakingOnly)
		obj.push_back(Pair("wallet_status", "stakingonly"));
	if (pwalletMain->IsLocked() && pwalletMain->IsCrypted())
		obj.push_back(Pair("wallet_status", "locked"));

	return obj;
}