bool CWallet::CommitTransaction(CTransactionRef tx, mapValue_t mapValue, std::vector<std::pair<std::string, std::string>> orderForm, std::string fromAccount, CReserveKey& reservekey, CConnman* connman, CValidationState& state)
{
    {
        LOCK2(cs_main, cs_wallet);

        CWalletTx wtxNew(this, std::move(tx));
        wtxNew.mapValue = std::move(mapValue);
        wtxNew.vOrderForm = std::move(orderForm);
        wtxNew.strFromAccount = std::move(fromAccount);
        wtxNew.fTimeReceivedIsTxTime = true;
        wtxNew.fFromMe = true;

        LogPrintf("CommitTransaction:\n%s", wtxNew.tx->ToString()); /* Continued */
        {
            // Take key pair from key pool so it won't be used again
            reservekey.KeepKey();

            // Add tx to wallet, because if it has change it's also ours,
            // otherwise just for transaction history.
            AddToWallet(wtxNew);

            // Notify that old coins are spent
            for (const CTxIn& txin : wtxNew.tx->vin)
            {
                CWalletTx &coin = mapWallet.at(txin.prevout.hash);
                coin.BindWallet(this);
                NotifyTransactionChanged(this, coin.GetHash(), CT_UPDATED);
            }
        }

        // Track how many getdata requests our transaction gets
        mapRequestCount[wtxNew.GetHash()] = 0;

        // Get the inserted-CWalletTx from mapWallet so that the
        // fInMempool flag is cached properly
        CWalletTx& wtx = mapWallet.at(wtxNew.GetHash());

        if (fBroadcastTransactions)
        {
            if(!wtx.AcceptVote()) {
                AbandonTransaction(wtx.GetHash());
            }
            // Broadcast
            if (!wtx.AcceptToMemoryPool(maxTxFee, state)) {
                LogPrintf("CommitTransaction(): Transaction cannot be broadcast immediately, %s\n", FormatStateMessage(state));
                // TODO: if we expect the failure to be long term or permanent, instead delete wtx from the wallet and return failure.
            } else {
                wtx.RelayWalletTransaction(connman);
            }
        }
    }
    return true;
}