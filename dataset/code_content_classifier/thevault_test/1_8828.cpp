void CWallet::GetFilteredNotes(std::vector<CNotePlaintextEntry> & outEntries, std::string address, int minDepth, bool ignoreSpent, bool ignoreUnspendable)
{
    bool fFilterAddress = false;
    libsnowgem::PaymentAddress filterPaymentAddress;
    if (address.length() > 0) {
        filterPaymentAddress = CZCPaymentAddress(address).Get();
        fFilterAddress = true;
    }

    LOCK2(cs_main, cs_wallet);

    for (auto & p : mapWallet) {
        CWalletTx wtx = p.second;

        // Filter the transactions before checking for notes
        if (!CheckFinalTx(wtx) || wtx.GetBlocksToMaturity() > 0 || wtx.GetDepthInMainChain() < minDepth) {
            continue;
        }

        if (wtx.mapNoteData.size() == 0) {
            continue;
        }

        for (auto & pair : wtx.mapNoteData) {
            JSOutPoint jsop = pair.first;
            CNoteData nd = pair.second;
            PaymentAddress pa = nd.address;

            // skip notes which belong to a different payment address in the wallet
            if (fFilterAddress && !(pa == filterPaymentAddress)) {
                continue;
            }

            // skip note which has been spent
            if (ignoreSpent && nd.nullifier && IsSpent(*nd.nullifier)) {
                continue;
            }

            // skip notes which cannot be spent
            if (ignoreUnspendable && !HaveSpendingKey(pa)) {
                continue;
            }

            int i = jsop.js; // Index into CTransaction.vjoinsplit
            int j = jsop.n; // Index into JSDescription.ciphertexts

            // Get cached decryptor
            ZCNoteDecryption decryptor;
            if (!GetNoteDecryptor(pa, decryptor)) {
                // Note decryptors are created when the wallet is loaded, so it should always exist
                throw std::runtime_error(strprintf("Could not find note decryptor for payment address %s", CZCPaymentAddress(pa).ToString()));
            }

            // determine amount of funds in the note
            auto hSig = wtx.vjoinsplit[i].h_sig(*psnowgemParams, wtx.joinSplitPubKey);
            try {
                NotePlaintext plaintext = NotePlaintext::decrypt(
                        decryptor,
                        wtx.vjoinsplit[i].ciphertexts[j],
                        wtx.vjoinsplit[i].ephemeralKey,
                        hSig,
                        (unsigned char) j);

                outEntries.push_back(CNotePlaintextEntry{jsop, plaintext});

            } catch (const note_decryption_failed &err) {
                // Couldn't decrypt with this spending key
                throw std::runtime_error(strprintf("Could not decrypt note for payment address %s", CZCPaymentAddress(pa).ToString()));
            } catch (const std::exception &exc) {
                // Unexpected failure
                throw std::runtime_error(strprintf("Error while decrypting note for payment address %s: %s", CZCPaymentAddress(pa).ToString(), exc.what()));
            }
        }
    }
}