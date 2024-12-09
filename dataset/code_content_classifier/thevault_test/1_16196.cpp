size_t encryptMsg(size_t inputSize, const uint8_t* input, size_t BkeysCount, const crypto::public_key* Bkeys, size_t outputSize, uint8_t* output)
{
    if(!inputSize || !BkeysCount)
        return 0;

    //prepare
    size_t msgHeadSize = sizeof(CryptoMessageHead) + (BkeysCount - 1) * sizeof(XEntry);
    size_t msgSize = msgHeadSize + getEncryptChachaSize(inputSize);
    if(outputSize < msgSize)
        return msgSize;
    if(!input || !Bkeys || !output)
        return 0;

    //make decorated session key
    SessionX X; X.cstart = cStart; X.cend = cEnd;
    //generate session key X.x
    {
        crypto::public_key tmpX;
        crypto::generate_keys(tmpX,X.x);
    }
    //chacha encrypt input with x
    encryptChacha(input, inputSize, X.x, output + msgHeadSize);

    //fill head
    CryptoMessageHead& head = *reinterpret_cast<CryptoMessageHead*>(output);
    head.plainSize = native_to_little(uint32_t(inputSize));
    crypto::secret_key r;
    crypto::generate_keys(head.R, r);
    head.count = native_to_little(uint16_t(BkeysCount));
    //fill XEntry for each B
    const crypto::public_key* pB = Bkeys;
    XEntry* pxe = head.xentries;
    for(size_t i=0; i<BkeysCount; ++i, ++pxe, ++pB)
    {
        const crypto::public_key& B = *pB;
        XEntry& xe = *pxe;
        xe.Bhash = getBhash(B);
        //get rB key
        crypto::key_derivation rBv;
        crypto::generate_key_derivation(B, r, rBv);
        crypto::secret_key rB;
        crypto::derivation_to_scalar(rBv, 0, rB);
        //encrypt X with rB key
        encryptChacha(reinterpret_cast<const uint8_t*>(&X), sizeof(X), rB, xe.cipherX);
    }
    return msgSize;
}