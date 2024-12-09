boost::optional<uint256> CWallet::GetNoteNullifier(const JSDescription& jsdesc,
                                                   const libsnowgem::PaymentAddress& address,
                                                   const ZCNoteDecryption& dec,
                                                   const uint256& hSig,
                                                   uint8_t n) const
{
    boost::optional<uint256> ret;
    auto note_pt = libsnowgem::NotePlaintext::decrypt(
        dec,
        jsdesc.ciphertexts[n],
        jsdesc.ephemeralKey,
        hSig,
        (unsigned char) n);
    auto note = note_pt.note(address);
    // SpendingKeys are only available if the wallet is unlocked
    libsnowgem::SpendingKey key;
    if (GetSpendingKey(address, key)) {
        ret = note.nullifier(key);
    }
    return ret;
}