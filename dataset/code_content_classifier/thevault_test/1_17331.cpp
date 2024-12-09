void CVnodePayments::FillBlockPayee(CMutableTransaction& txNew, int nBlockHeight, CAmount vnodePayment, CTxOut& txoutVnodeRet)
{
    // make sure it's not filled yet
    txoutVnodeRet = CTxOut();

    CScript payee;
    bool foundMaxVotedPayee = true;

    if (!mnpayments.GetBlockPayee(nBlockHeight, payee)) {
        // no vnode detected...
        // LogPrintf("no vnode detected...\n");
        foundMaxVotedPayee = false;
        int nCount = 0;
        CVnode* winningNode = mnodeman.GetNextVnodeInQueueForPayment(nBlockHeight, true, nCount);
        if (!winningNode) {
            // ...and we can't calculate it on our own
            LogPrintf("CVnodePayments::FillBlockPayee -- Failed to detect vnode to pay\n");
            return;
        }
        // fill payee with locally calculated winner and hope for the best
        payee = GetScriptForDestination(winningNode->pubKeyCollateralAddress.GetID());
        LogPrintf("payee=%s\n", winningNode->ToString());
    }
    txoutVnodeRet = CTxOut(vnodePayment, payee);
    txNew.vout.push_back(txoutVnodeRet);

    CTxDestination address1;
    ExtractDestination(payee, address1);
    CBitcoinAddress address2(address1);
    if (foundMaxVotedPayee) {
        LogPrintf("CVnodePayments::FillBlockPayee::foundMaxVotedPayee -- Vnode payment %lld to %s\n", vnodePayment, address2.ToString());
    } else {
        LogPrintf("CVnodePayments::FillBlockPayee -- Vnode payment %lld to %s\n", vnodePayment, address2.ToString());
    }
}