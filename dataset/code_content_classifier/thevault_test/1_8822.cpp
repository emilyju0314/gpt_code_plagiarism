bool CWallet::UpdateNullifierNoteMap()
{
    {
        LOCK(cs_wallet);

        if (IsLocked())
            return false;

        ZCNoteDecryption dec;
        for (std::pair<const uint256, CWalletTx>& wtxItem : mapWallet) {
            for (mapNoteData_t::value_type& item : wtxItem.second.mapNoteData) {
                if (!item.second.nullifier) {
                    if (GetNoteDecryptor(item.second.address, dec)) {
                        auto i = item.first.js;
                        auto hSig = wtxItem.second.vjoinsplit[i].h_sig(
                            *psnowgemParams, wtxItem.second.joinSplitPubKey);
                        item.second.nullifier = GetNoteNullifier(
                            wtxItem.second.vjoinsplit[i],
                            item.second.address,
                            dec,
                            hSig,
                            item.first.n);
                    }
                }
            }
            UpdateNullifierNoteMapWithTx(wtxItem.second);
        }
    }
    return true;
}