bool Secp256K1::createPublicKeyFromPriv(const std::vector<uint8_t>& privateKey)
{
    privKey = privateKey;
    //verify priv key
    if (!verifyKey()) {
        throw Secp256K1Exception("Unable to create and verify key:  ");
    }

    if (!createPublicKey()) {
        throw Secp256K1Exception("Unable to create publick key");
    }
    return true;
}