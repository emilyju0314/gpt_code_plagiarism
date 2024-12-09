inline int _Log2(unsigned int n)
	{
		int r = 0;
		while (n >>= 1) r++;
		return r;
	}