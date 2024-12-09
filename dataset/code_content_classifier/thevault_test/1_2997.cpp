static int randomParkAndMiller(long *seed0)
{
	const long a =      16807;
	const long m = 2147483647;
	const long q =     127773;  /* m div a */
	const long r =       2836;  /* m mod a */

	long seed = *seed0;
	long hi   = seed / q;
	long lo   = seed % q;
	long test = a * lo - r * hi;
	if (test > 0)
		seed = test;
	else
		seed = test + m;
	*seed0 = seed;

	return (long)(seed * 4.656612875245797e-10 * 256);
}