double PackMimeHTTPFlowArriveRandomVariable::value(void) {
	double yt;

	if (fARIMA_ == NULL) 		
		initialize();

	yt = fARIMA_->Next();
	yt = yt * sigmaEpsilon_ + rng_->rnorm() * sigmaNoise_;
	yt = rng_->qweibull(rng_->pnorm(yt), weibullShape_, weibullScale_);

	// adjust by const_ and mean_ (by default, this does nothing)
	if (const_ == 0) {
		const_ = mean_ / avg(1);
	}

	return(yt * const_);
}