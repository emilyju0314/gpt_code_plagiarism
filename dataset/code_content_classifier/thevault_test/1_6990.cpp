double QA::bufOptScen1(int layer, int layers, double currrate, 
		       double slope, int backoffs)
{
	double smallt, larget, side, rate;
  
	if (backoffs < 0) {
		panic("# ERROR: backoff: %d in bufOptScen1\n", 
		      backoffs);
	}
	rate = currrate/pow(2,backoffs);
	side = LAYERBW_*layers - (rate + layer*LAYERBW_);
	if (side <= 0.0) 
		return(0.0);
	larget = BufNeed(side, slope);
	side = LAYERBW_*layers - (rate + (layer+1)*LAYERBW_);
	if (side < 0.0) 
		side = 0.0;
	smallt = BufNeed(side, slope);

	return (larget-smallt);
}