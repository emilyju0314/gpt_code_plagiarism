Bytes Prng::rand()
{
	Bytes rnd(AES_BLOCK_SIZE);
	AES_ecb_encrypt(&m_state[0], &rnd[0], &m_key, AES_ENCRYPT);

	cnt++;

	// update state
	long long cnt = *(long long*)(&m_state[m_state.size()-1-sizeof(cnt)]);
	cnt++;
	*(long long*)(&m_state[m_state.size()-1-sizeof(cnt)]) = cnt;

	return rnd;
}