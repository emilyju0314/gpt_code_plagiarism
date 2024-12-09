void PolarSatPosition::set(double Altitude, double Lon, double Alpha, double Incl)
{
	if (Altitude < 0) {
		fprintf(stderr, "PolarSatPosition:  altitude out of \
		   bounds: %f\n", Altitude);
		exit(1);
	}
	initial_.r = Altitude + EARTH_RADIUS; // Altitude in km above the earth
	if (Alpha < 0 || Alpha >= 360) {
		fprintf(stderr, "PolarSatPosition:  alpha out of bounds: %f\n", 
		    Alpha);
		exit(1);
	}
	initial_.theta = DEG_TO_RAD(Alpha);
	if (Lon < -180 || Lon > 180) {
		fprintf(stderr, "PolarSatPosition:  lon out of bounds: %f\n", 
		    Lon);
		exit(1);
	}
	if (Lon < 0)
		initial_.phi = DEG_TO_RAD(360 + Lon);
	else
		initial_.phi = DEG_TO_RAD(Lon);
	if (Incl < 0 || Incl > 180) {
		// retrograde orbits = (90 < Inclination < 180)
		fprintf(stderr, "PolarSatPosition:  inclination out of \
		    bounds: %f\n", Incl); 
		exit(1);
	}
	inclination_ = DEG_TO_RAD(Incl);
	// XXX: can't use "num = pow(initial_.r,3)" here because of linux lib
	double num = initial_.r * initial_.r * initial_.r;
	period_ = 2 * PI * sqrt(num/MU); // seconds
}