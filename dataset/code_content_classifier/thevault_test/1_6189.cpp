int YARPObjectContainer::FindObject (YARPImageOf<YarpPixelBGR>& scan)
{
	if (!m_active)
	{
		printf ("YARPObjectContainer: need to update stats first\n");
		m_last_known_object = -1;
		m_orientation = 0;
		m_displacement = 0;
		return -1;
	}

	double x, y, quality;
	double max_quality = 0; 
	int max_obj = -1;
	double max_x = 0, max_y = 0;

	const int NOBJ = m_canonical_stats->m_goodneurons;

	for (int obj = 0; obj < NOBJ; obj++)
	{
		m_locator[obj].BackProject (scan, m_backp[obj]);

		double ex, ey;
		m_locator[obj].GetExtent (ex, ey);

		ex *= SCALE;
		ey *= SCALE;

		if (m_locator[obj].Find (ex, ey, x, y, quality) >= 0)
		{
			double mean = 0, stddev = 0;
			const double THR = 2.0;
			m_locator[obj].GetExpectancy (mean, stddev);

			bool thr_cond = (fabs(quality - mean) < stddev * THR) ? true : false;

#ifdef _DEBUG
			printf ("object: %d location: %lf %lf q: %lf\n", obj, x, y, quality);
#endif
			if (quality > max_quality && thr_cond)
			{
				max_quality = quality;
				max_obj = obj;
				max_x = x;
				max_y = y;
			}
		}
	}

	m_last_known_object = max_obj;

	if (max_obj == -1)
	{
		printf ("I (COG) don't know about this object, if there's one at all!\n");
		m_orientation = 0;
		m_displacement = 0;
		return -1;
	}

#ifdef _DEBUG
	printf ("object is %d\n", max_obj);
#endif

	// non valid orientation and displacement!
	m_orientation = 0;
	m_displacement = 0;
	return max_obj;
}