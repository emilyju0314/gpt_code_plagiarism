double CardinalityCounter::Size() const
	{
	double answer = 0;
	for ( unsigned int i = 0; i < m; i++ )
		answer += pow(2, -((int)buckets[i]));

	answer = 1 / answer;
	answer = (alpha_m * m * m * answer);

	if ( answer <= 5.0 * (m / 2) )
		return m * log(((double)m) / V);

	else if ( answer <= (pow(2, 64) / 30) )
		return answer;

	else
		return -pow(2, 64) * log(1 - (answer / pow(2, 64)));
	}