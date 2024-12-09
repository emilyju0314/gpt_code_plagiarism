inline int modulus(int a, int b)
	{
		if (a < 0) return b + (a %  b);
		else return (a % b);
	}