double QA::bufOptScen2(int layer, int layers, double currrate, 
		       double slope, int backoffs)
{
	double bufopt = 0.0;
	int bmin, done;

	if(backoffs < 0) {
		panic("# ERROR: backoff: %d in bufOptScen2\n", 
			backoffs);
	}
	if ((currrate/pow(2,backoffs)) >= layers*LAYERBW_)
		return(0.0);

	bmin = 0;
	done = 0;
	while ((!done) && bmin<=backoffs) {
		if(currrate/pow(2,bmin) >= LAYERBW_*layers)
			bmin++;
		else 
			done++;
	}
	// buf required for the first triangle
	// we could have dec bmin and go for 1 backoff as well
	bufopt = bufOptScen1(layer, layers, currrate/pow(2,bmin), slope, 0);
  
	// remaining sequential backoffs
	bufopt += (backoffs - bmin)*BufNeed(layers*LAYERBW_/2, slope);
	return(bufopt);
}