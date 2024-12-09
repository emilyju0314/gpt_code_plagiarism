BOOST_FOREACH(CAmount nDenom, vecPrivateSendDenominations)
        {
            BOOST_FOREACH(const COutput &out, vCoins)
            {
                //make sure it's the denom we're looking for, round the amount up to smallest denom
                if (out.tx->vout[out.i].nValue == nDenom && nValueRet + nDenom < nTargetValue + nSmallestDenom) {
                    CTxIn txin = CTxIn(out.tx->GetHash(), out.i);
                    int nRounds = GetInputPrivateSendRounds(txin);
                    // make sure it's actually anonymized
                    if (nRounds < nPrivateSendRounds) continue;
                    nValueRet += nDenom;
                    setCoinsRet.insert(make_pair(out.tx, out.i));
                }
            }
        }