std::vector<COutput> CActiveMasternode::SelectCoinsMasternode()
{
    std::vector<COutput> vCoins;
    std::vector<COutput> filteredCoins;

    auto m_wallet = GetMainWallet();
    if (!m_wallet)
        return filteredCoins;

    // Retrieve all possible outputs
    m_wallet->AvailableCoins(vCoins);

    // Filter appropriate coins
    for (const COutput& out : vCoins) {
        if(out.tx->tx->nVersion >= TX_ELE_VERSION){
            if (out.tx->tx->vpout[out.i].nValue == Params().MasternodeCollateral())
                filteredCoins.push_back(out);           
        }
        else{
            if (out.tx->tx->vout[out.i].nValue == Params().MasternodeCollateral()) 
                filteredCoins.push_back(out);
        }
    }

    return filteredCoins;
}