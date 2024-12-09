void DS_EncPrivKey::updatePubKey() {
	uint8_t tmp[ENC_PUBKEY_SIZE_BYTES];
	if (crypto_scalarmult_base(tmp, key) == 0) {
		pubkey.SetFromBinaryData(tmp, ENC_PUBKEY_SIZE_BYTES);
	} else {
		pubkey.SetNull();
	}
}