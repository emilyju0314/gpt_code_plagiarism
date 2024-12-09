double PackMimeHTTPXmitRandomVariable::value(void) {
	double yt, p;
	    
	if (fARIMA_ == NULL)
		initialize();

	yt = fARIMA_->Next();
	yt = yt * sigmaEpsilon_ + rng_->rnorm() * sigmaNoise_;
	p = rng_->pnorm(yt);
	p = -log(1-p)/log(10.0);
	yt = rtt_invcdf[type_].LinearInterpolate(p);
	yt = pow(yt, WEIBULL_SHAPE[type_]);

	// split in half for DelayBox -M. Weigle 9/17/01
	if (mean_ < 0)
		return(yt/2);
	else {
		if (const_ <0)
			const_ = mean_/avg();
		return(yt/2*const_);
	}
}