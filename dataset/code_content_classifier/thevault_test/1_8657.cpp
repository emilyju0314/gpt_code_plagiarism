void crypto::gen_rnd_perm(uint32_t* perm, uint32_t neles) {
	uint32_t* rndbuf = (uint32_t*) malloc(sizeof(uint32_t) * neles);
	uint32_t i, j;
	//TODO Generate random numbers (CAREFUL: NOT UNIFORM)
	gen_rnd((uint8_t*) rndbuf, sizeof(uint32_t) * neles);
	for (i = 0; i < neles; i++) {
		perm[i] = i;
	}
	for (i = 0; i < neles; i++) {
		j = rndbuf[i] % neles; //NOT UNIFORM
		swap(perm[i], perm[j]);
	}
	free(rndbuf);
}