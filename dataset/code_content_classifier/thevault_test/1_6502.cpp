bool PolarSatPosition::isascending()
{	
	double partial = (fmod(NOW + time_advance_, period_)/period_) * 2*PI; //rad
	double theta_cur = fmod(initial_.theta + partial, 2*PI);
	if ((theta_cur > PI/2)&&(theta_cur < 3*PI/2)) {
		return 0;
	} else {
		return 1;
	}
}