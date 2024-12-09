bool
MergeOpFrame::doApply(Application& app, LedgerDelta& delta,
                      LedgerManager& ledgerManager)
{
    AccountFrame::pointer otherAccount;
    Database& db = ledgerManager.getDatabase();
    auto const& sourceAccount = mSourceAccount->getAccount();
    int64 sourceBalance = sourceAccount.balance;

    otherAccount =
        AccountFrame::loadAccount(delta, mOperation.body.destination(), db);

    if (!otherAccount)
    {
        app.getMetrics()
            .NewMeter({"op-merge", "failure", "no-account"}, "operation")
            .Mark();
        innerResult().code(ACCOUNT_MERGE_NO_ACCOUNT);
        return false;
    }

    if (ledgerManager.getCurrentLedgerVersion() > 4 &&
        ledgerManager.getCurrentLedgerVersion() < 8)
    {
        // in versions < 8, merge account could be called with a stale account
        AccountFrame::pointer thisAccount =
            AccountFrame::loadAccount(delta, mSourceAccount->getID(), db);
        if (!thisAccount)
        {
            app.getMetrics()
                .NewMeter({"op-merge", "failure", "no-account"}, "operation")
                .Mark();
            innerResult().code(ACCOUNT_MERGE_NO_ACCOUNT);
            return false;
        }
        if (ledgerManager.getCurrentLedgerVersion() > 5)
        {
            sourceBalance = thisAccount->getBalance();
        }
    }

    if (mSourceAccount->isImmutableAuth())
    {
        app.getMetrics()
            .NewMeter({"op-merge", "failure", "static-auth"}, "operation")
            .Mark();
        innerResult().code(ACCOUNT_MERGE_IMMUTABLE_SET);
        return false;
    }

    if (sourceAccount.numSubEntries != sourceAccount.signers.size())
    {
        app.getMetrics()
            .NewMeter({"op-merge", "failure", "has-sub-entries"}, "operation")
            .Mark();
        innerResult().code(ACCOUNT_MERGE_HAS_SUB_ENTRIES);
        return false;
    }

    if (!otherAccount->addBalance(sourceBalance))
    {
        throw std::runtime_error("merge overflowed destination balance");
    }

    otherAccount->storeChange(delta, db);

    if (ledgerManager.getCurrentLedgerVersion() < 8)
    {
        // we have to compensate for buggy behavior in version < 8
        // to avoid tripping invariants
        AccountFrame::pointer thisAccount =
            AccountFrame::loadAccount(delta, mSourceAccount->getID(), db);
        if (!thisAccount)
        {
            // ignore double delete
        }
        else
        {
            mSourceAccount->storeDelete(delta, db);
        }
    }
    else
    {
        mSourceAccount->storeDelete(delta, db);
    }

    app.getMetrics()
        .NewMeter({"op-merge", "success", "apply"}, "operation")
        .Mark();
    innerResult().code(ACCOUNT_MERGE_SUCCESS);
    innerResult().sourceAccountBalance() = sourceBalance;
    return true;
}