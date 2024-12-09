long RNG::rand_int (long low, long high) 
{ 
	//	return (long) low + (long) (((double) (high-low) * drn) + 0.5);
	return ((long) (low + (unsigned long) (((unsigned long) 
						(high-low+1)) * rand_u01())));
}