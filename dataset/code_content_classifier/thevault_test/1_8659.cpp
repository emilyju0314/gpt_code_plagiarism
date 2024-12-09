void gen_secure_random(uint8_t* dest, uint32_t nbytes) {
	int32_t randomData = open("/dev/random", O_RDONLY);
	uint32_t bytectr = 0;
	while (bytectr < nbytes) {
		uint32_t result = read(randomData, dest + bytectr, nbytes - bytectr);
		if (result < 0) {
			cerr << "Unable to read from /dev/random, exiting" << endl;
			exit(0);
		}
		bytectr += result;
	}
	close(randomData);
}