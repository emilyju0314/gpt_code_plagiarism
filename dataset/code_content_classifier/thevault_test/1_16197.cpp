size_t decryptMsg(size_t inputSize, const uint8_t* input, const crypto::secret_key& bkey, size_t outputSize, uint8_t* output)
{
    if(!input || inputSize <= sizeof(CryptoMessageHead))
        return 0;
    //prepare
    const CryptoMessageHead& head = *reinterpret_cast<const CryptoMessageHead*>(input);
    size_t head_count = little_to_native(head.count);
    size_t head_plainSize = little_to_native(head.plainSize);
    size_t msgHeadSize = sizeof(CryptoMessageHead) + ((size_t)(head_count - 1)) * sizeof(XEntry);
    size_t msgSize = msgHeadSize + getEncryptChachaSize(head_plainSize);
    if(inputSize < msgSize)
        return 0;
    if(outputSize < head_plainSize)
        return head_plainSize;
    if(!output)
        return 0;

    //get Bhash from b
    const crypto::secret_key& b = bkey;
    uint32_t Bhash;
    {
        crypto::public_key B;
        bool res = crypto::secret_key_to_public_key(bkey, B);
        if(!res) return false; //corrupted key
        Bhash = getBhash(B);
    }
    //find XEntry for B
    const XEntry* pxe = head.xentries;
    for(size_t i=0; i<head_count; ++i, ++pxe)
    {
        const XEntry& xe = *pxe;
        if(xe.Bhash != Bhash) continue;
        //get bR key
        crypto::key_derivation bRv;
        crypto::generate_key_derivation(head.R, b, bRv);
        crypto::secret_key bR;
        crypto::derivation_to_scalar(bRv, 0, bR);
        //decrypt to X
        SessionX X;
        decryptChacha(xe.cipherX, sizeof(xe.cipherX), bR, reinterpret_cast<uint8_t*>(&X));
        if(X.cstart != cStart || X.cend != cEnd) continue;
        //decrypt with session key
        decryptChacha(input + msgHeadSize, getEncryptChachaSize(head_plainSize), X.x, output);
        return head_plainSize;
    }
    return 0;
}