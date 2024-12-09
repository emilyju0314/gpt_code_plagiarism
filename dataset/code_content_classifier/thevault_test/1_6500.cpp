TermSatPosition::TermSatPosition(double Theta, double Phi)  {
	initial_.r = EARTH_RADIUS;
	period_ = EARTH_PERIOD; // seconds
	set(Theta, Phi);
	type_ = POSITION_SAT_TERM;
}