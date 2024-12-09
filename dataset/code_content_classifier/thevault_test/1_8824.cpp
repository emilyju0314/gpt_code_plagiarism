mapNoteData_t CWallet::FindMyNotes(const CTransaction& tx) const
{
    LOCK(cs_SpendingKeyStore);
    uint256 hash = tx.GetHash();

    mapNoteData_t noteData;
    for (size_t i = 0; i < tx.vjoinsplit.size(); i++) {
        auto hSig = tx.vjoinsplit[i].h_sig(*psnowgemParams, tx.joinSplitPubKey);
        for (uint8_t j = 0; j < tx.vjoinsplit[i].ciphertexts.size(); j++) {
            for (const NoteDecryptorMap::value_type& item : mapNoteDecryptors) {
                try {
                    auto address = item.first;
                    JSOutPoint jsoutpt {hash, i, j};
                    auto nullifier = GetNoteNullifier(
                        tx.vjoinsplit[i],
                        address,
                        item.second,
                        hSig, j);
                    if (nullifier) {
                        CNoteData nd {address, *nullifier};
                        noteData.insert(std::make_pair(jsoutpt, nd));
                    } else {
                        CNoteData nd {address};
                        noteData.insert(std::make_pair(jsoutpt, nd));
                    }
                    break;
                } catch (const note_decryption_failed &err) {
                    // Couldn't decrypt with this decryptor
                } catch (const std::exception &exc) {
                    // Unexpected failure
                    LogPrintf("FindMyNotes(): Unexpected error while testing decrypt:\n");
                    LogPrintf("%s\n", exc.what());
                }
            }
        }
    }
    return noteData;
}