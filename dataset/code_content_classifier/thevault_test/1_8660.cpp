void Prng::srand()
{
	Bytes seed(AES_BLOCK_SIZE);

	FILE *fp = fopen(RANDOM_FILE, "r");
	fread(&seed[0], 1, seed.size(), fp);
	fclose(fp);

	seed_rand(seed);
}