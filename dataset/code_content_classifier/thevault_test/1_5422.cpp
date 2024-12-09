double	TransOpFilmStream::operator () (double x) const
{
	static const double  sc10    = 1024;
	static const double  bl12    = 64;
	static const double  wl12    = 3840;
	static const double  mi10    =    3 / sc10;
	static const double  ma10    = 1020 / sc10;
	static const double  sp      = 500;
	static const double  sl      = 0.02714;

	double         y = x;
	if (_inv_flag)
	{
		x = fstb::limit (x, mi10, ma10);
		const double   sensor = pow (10, x * (sc10 / sp)) / sl;
		y = (sensor - bl12) / (wl12 - bl12);
	}
	else
	{
		const double   sensor = bl12 + x * (wl12 - bl12);
		if (sensor <= 37)
		{
			y = 0;
		}
		else
		{
			y = (sp / sc10) * log10 (sl * sensor);
			y = fstb::limit (y, mi10, ma10);
		}
	}

	return (y);
}