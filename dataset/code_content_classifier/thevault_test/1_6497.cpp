int PackMimeHTTPFileSizeRandomVariable::qfsize1(double p)
{
	int state;
	double yt;

	/* first convert this to conditional probablity */
	if(p > FSIZE1_PROB_A){
		state = 1; 
		p = (p-FSIZE1_PROB_A)/(1-FSIZE1_PROB_A);
	}else {
		state = 0;
		p = p/FSIZE1_PROB_A;
	}

	if (state==1) 
		p=log(1-p)/LOG2;
	yt = fsize_invcdf[1][state].LinearInterpolate(p);
	if (state==1) 
		yt=exp(LOG2*yt); 

	return((int) yt);
}