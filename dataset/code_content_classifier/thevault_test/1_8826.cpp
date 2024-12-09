void CWallet::AvailableCoins(vector<COutput>& vCoins, bool fOnlyConfirmed, const CCoinControl *coinControl, bool fIncludeZeroValue, bool fIncludeCoinBase, AvailableCoinsType coin_type, bool useIX) const
{
    vCoins.clear();

    {
        LOCK2(cs_main, cs_wallet);
        int count = 1;
        for (map<uint256, CWalletTx>::const_iterator it = mapWallet.begin(); it != mapWallet.end(); ++it)
        {
            const uint256& wtxid = it->first;
            const CWalletTx* pcoin = &(*it).second;

            if (!CheckFinalTx(*pcoin))
                continue;

            if (fOnlyConfirmed && !pcoin->IsTrusted())
                continue;

            if (pcoin->IsCoinBase() && !fIncludeCoinBase)
                continue;

            if (pcoin->IsCoinBase() && pcoin->GetBlocksToMaturity() > 0)
                continue;

            int nDepth = pcoin->GetDepthInMainChain(false);
            if (useIX && nDepth < 6)
            {
                continue;
            }

            for (unsigned int i = 0; i < pcoin->vout.size(); i++) {
                bool found = false;
                if (coin_type == ONLY_DENOMINATED) {
                    found = IsDenominatedAmount(pcoin->vout[i].nValue);
                } else if (coin_type == ONLY_NOT10000IFMN) {
                    found = !(fMasterNode && pcoin->vout[i].nValue == 10000 * COIN);
                } else if (coin_type == ONLY_NONDENOMINATED_NOT10000IFMN) {
                    if (IsCollateralAmount(pcoin->vout[i].nValue)) continue; // do not use collateral amounts
                    found = !IsDenominatedAmount(pcoin->vout[i].nValue);
                    if (found && fMasterNode) found = pcoin->vout[i].nValue != 10000 * COIN; // do not use Hot MN funds
                } else if (coin_type == ONLY_10000) {
                    found = pcoin->vout[i].nValue == 10000 * COIN;
                } else {
                    found = true;
                }

                if(!found) continue;

                isminetype mine = IsMine(pcoin->vout[i]);

                if (IsSpent(wtxid, i))
                {
                    continue;
                }
                if (mine == ISMINE_NO)
                {
                    continue;
                }
                if (IsLockedCoin((*it).first, i) && coin_type != ONLY_10000)
                {
                    continue;
                }
                if (coinControl && coinControl->HasSelected() && !coinControl->fAllowOtherInputs && !coinControl->IsSelected((*it).first, i))
                {
                    continue;
                }

                bool fIsSpendable = false;
                if ((mine & ISMINE_SPENDABLE) != ISMINE_NO)
                    fIsSpendable = true;

                vCoins.emplace_back(COutput(pcoin, i, nDepth, fIsSpendable));
            }
        }
    }
}