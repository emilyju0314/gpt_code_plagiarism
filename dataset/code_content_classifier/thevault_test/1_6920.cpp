double RNG::exp_rand (void)
{
	/** q[k-1] = sum(log(2)^k / k!)  k=1,..,n, 
	 *  The highest n (here 8) is determined by q[n-1] = 1.0 
	 *  within standard precision 
	 */
	const double q[] = {
		0.6931471805599453,
		0.9333736875190459,
		0.9888777961838675,
		0.9984959252914960,
		0.9998292811061389,
		0.9999833164100727,
		0.9999985691438767,
		0.9999998906925558,
		0.9999999924734159,
		0.9999999995283275,
		0.9999999999728814,
		0.9999999999985598,
		0.9999999999999289,
		0.9999999999999968,
		0.9999999999999999,
		1.0000000000000000
	};
	double a, u, ustar, umin;
	int i;

	a = 0.;
	u = uniform();
	for (;;) {
		u += u;
		if (u > 1.0)
			break;
		a += q[0];
	}
	u -= 1.;

	if (u <= q[0])
		return a + u;

	i = 0;
	ustar = uniform();
	umin = ustar;
	do {
		ustar = uniform();
		if (ustar < umin)
			umin = ustar;
		i++;
	} while (u > q[i]);

	return a + umin * q[0];
}