double PackMimeHTTPFileSizeRandomVariable::value() 
{
	int yt;

	if (fARIMA_ == NULL)
		initialize();

	if (type_ == PACKMIME_RSP_SIZE) {
		/* regenerate the runlen if a run is finished */
		if (runlen_ <= 0) { // XXX Y. G. changed to <= from ==
			state_ = 1-state_;
			runlen_ = (int) ceil(rng_->rweibull(shape_[state_], 
							    scale_[state_]));
		}
		yt = rfsize0(state_); 
		runlen_--;
		
		// adjust by const_ and mean_ (by default, this does nothing)
		if (const_ == 0) {
			const_ = mean_ / avg();
		}
		return (double) (yt * const_);
	} else if (type_ == PACKMIME_REQ_SIZE) {		
		double yx;
		yx = fARIMA_->Next();
		yx = yx * sigmaEpsilon_ + rng_->rnorm() * sigmaNoise_;
		yt = qfsize1(rng_->pnorm(yx));

		// adjust by const_ and mean_ (by default, this does nothing)
		if (const_ == 0) {
			const_ = mean_ / avg();
		}
		return (double) (yt * const_);
	}
	return 0;
}