void CBQClass::delayed(double now)
{
	double delay = undertime_ - now + extradelay_;

	if (delay > 0 && !delayed_) {
		undertime_ += extradelay_;
		undertime_ -= (1-POWEROFTWO) * avgidle_;
		delayed_ = 1;
	}
}