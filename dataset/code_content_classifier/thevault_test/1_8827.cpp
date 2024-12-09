BOOST_FOREACH (CAmount v, obfuScationDenominations) {
            BOOST_FOREACH (const COutput& out, vCoins) {
                if (out.tx->vout[out.i].nValue == v                                               //make sure it's the denom we're looking for
                    && nValueRet + out.tx->vout[out.i].nValue < nTargetValue + (0.1 * COIN) + 100 //round the amount up to .1 XSG over
                    ) {
                    CTxIn vin = CTxIn(out.tx->GetHash(), out.i);
                    int rounds = GetInputObfuscationRounds(vin);
                    // make sure it's actually anonymized
                    if (rounds < nSnowgemSendRounds) continue;
                    nValueRet += out.tx->vout[out.i].nValue;
                    setCoinsRet.insert(make_pair(out.tx, out.i));
                }
            }
        }