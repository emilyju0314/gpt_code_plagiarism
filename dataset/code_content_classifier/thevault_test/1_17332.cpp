void CVnodePayments::Sync(CNode* pnode)
{
    LOCK(cs_mapVnodeBlocks);

    if (!pCurrentBlockIndex)
        return;

    int nInvCount = 0;

    for (int h = pCurrentBlockIndex->nHeight; h < pCurrentBlockIndex->nHeight + 20; h++) {
        if (mapVnodeBlocks.count(h)) {
            BOOST_FOREACH (CVnodePayee& payee, mapVnodeBlocks[h].vecPayees) {
                std::vector<uint256> vecVoteHashes = payee.GetVoteHashes();
                BOOST_FOREACH (uint256& hash, vecVoteHashes) {
                    if (!HasVerifiedPaymentVote(hash))
                        continue;
                    pnode->PushInventory(CInv(MSG_VNODE_PAYMENT_VOTE, hash));
                    nInvCount++;
                }
            }
        }
    }

    LogPrintf("CVnodePayments::Sync -- Sent %d votes to peer %d\n", nInvCount, pnode->id);
    pnode->PushMessage(NetMsgType::SYNCSTATUSCOUNT, VNODE_SYNC_MNW, nInvCount);
}