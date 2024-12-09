inline double modulus(double a, double b)
	{
		if (a < 0) return a - static_cast<int>(a / b - 1) * b;
		else return a - static_cast<int>(a / b) * b;
	}