void crypto::fixed_key_aes_hash(AES_KEY_CTX* aes_key, uint8_t* resbuf, uint32_t noutbytes, uint8_t* inbuf, uint32_t ninbytes) {
	uint32_t i;
	int32_t dummy;

	memset(aes_hash_in_buf, 0, AES_BYTES);
	memcpy(aes_hash_in_buf, inbuf, ninbytes);

	//two encryption iterations TODO: not secure since both blocks are treated independently, implement DM or MMO
	EVP_EncryptUpdate(aes_key, aes_hash_out_buf, &dummy, aes_hash_in_buf, AES_BYTES);

	((uint64_t*) aes_hash_out_buf)[0] ^= ((uint64_t*) aes_hash_in_buf)[0];
	((uint64_t*) aes_hash_out_buf)[1] ^= ((uint64_t*) aes_hash_in_buf)[1];

	memcpy(resbuf, aes_hash_out_buf, noutbytes);
}