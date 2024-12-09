void crypto::gen_common_seed(prf_state_ctx* prf_state, CSocket& sock) {
	uint8_t *seed_buf, *seed_rcv_buf;
	uint32_t seed_bytes, i;

	seed_bytes = get_aes_key_bytes();
	seed_buf = (uint8_t*) malloc(seed_bytes);
	seed_rcv_buf = (uint8_t*) malloc(seed_bytes);

	//randomly generate and exchange seed bytes:
	gen_rnd(seed_buf, seed_bytes);
	sock.Send(seed_buf, seed_bytes);
	sock.Receive(seed_rcv_buf, seed_bytes);

	//xor both seeds
	for (i = 0; i < seed_bytes; i++) {
		seed_buf[i] ^= seed_rcv_buf[i];
	}

	init_prf_state(prf_state, seed_buf);

	free(seed_buf);
	free(seed_rcv_buf);
}