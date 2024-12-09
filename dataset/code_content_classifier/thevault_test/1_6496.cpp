int PackMimeHTTPFileSizeRandomVariable::rfsize0(int state)
{
	double yt, p;
  
	p = rng_->uniform();
	if (state==1) 
		p = log(1-p)/LOG2; 
	yt = fsize_invcdf[0][state].LinearInterpolate(p);
	if (state==1) 
		yt = exp(LOG2*yt); 

	return((int) yt);
}