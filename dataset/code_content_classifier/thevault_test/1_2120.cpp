void print_solid(unsigned long long int n)
{
	unsigned long long size = 0;
	for (unsigned long i = 0; i < SOLID.size(); i++) {
		if (SOLID[i].shape == BOX) {
			size++;
			printf("%llu:\t|", size);
			for (unsigned long long idx = 0; idx < TRANSACTION_BITMASK_LEN; idx++) {
				for (unsigned int b = 0; b < 64; b++) {
					if (isbitset(SOLID[i].bitmask[idx], b)) {
						printf("%llu|", idx * 64 + b + 1); 
					} 
				} 
			} 
			printf("\tsupp==%llu (%.2f)\n", SOLID[i].support, ((double)SOLID[i].support) / n);
		}
	}
}