double TcpAgent::limited_slow_start(double cwnd, int max_ssthresh, double increment)
{
        if (max_ssthresh <= 0) {
	  	return increment;
	} else {
                double increment1 = 0.0;
		int round = int(cwnd / (double(max_ssthresh)/2.0));
		if (round > 0) {
		  	increment1 = 1.0/double(round); 
		} 
		if (increment < increment1) {
		  	return increment1;
		} else {
		  	return increment;
		}
	}
}