void GeoSatPosition::set(double longitude)
{
	if (longitude < -180 || longitude > 180)
		fprintf(stderr, "GeoSatPosition:  longitude out of bounds %f\n",
		    longitude);
	if (longitude < 0)
		initial_.phi = DEG_TO_RAD(360 + longitude);
	else
		initial_.phi = DEG_TO_RAD(longitude);
}