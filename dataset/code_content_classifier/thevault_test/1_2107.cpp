int read_bitmap(char * inpname, unsigned long long &n, unsigned int &m)
{
	START("Read bitmap");

	FILE * f = fopen(inpname, "rb");
	PRINT("File==`%s'\t", inpname);
	assert(f != NULL);
	fread(&(n), sizeof(unsigned long long int), 1, f);
	PRINT("n==%llu\t", n);
	assert(n >= 1 && n <= n_MAX);
	fread(&(m), sizeof(unsigned int), 1, f);
	PRINT("m==%lu\t", m);
	assert(m >= 1 && m <= m_MAX);
	fread(&TRANSACTION_BITMASK_LEN, sizeof(unsigned int), 1, f);
	assert(TRANSACTION_BITMASK_LEN >= 1 && TRANSACTION_BITMASK_LEN <= BITMASK_LEN_MAX);

	PRINT("Number of transactions n==%llu\nNumber of items m==%d\nBitmask len==%d\n", n, m, TRANSACTION_BITMASK_LEN);

	int res = init_bitmap(n, m);
	assert(res == 0);

	for (unsigned int i = 0; i < n; i++) {
		for (unsigned long long j = 0; j < TRANSACTION_BITMASK_LEN; j++) {
			fread(&BITMAP[i][j], sizeof(bitmask_t), 1, f);
			assert(BITMAP[i][j] >= 0);
			//			PRINT("TIDBITMAP[%lu][%llu]==%llu\t", i, j, TIDBITMAP[i][j]);
		}
	}
	fclose(f);
	FINISH("Read bitmap");

	return 0;
}