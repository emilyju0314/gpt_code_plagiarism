int YARPObjectContainer::Find (YARPImageOf<YarpPixelBGR>& scan, YARPImageOf<YarpPixelBGR>& out, int& bestaction)
{
	if (!m_active)
	{
		printf ("YARPObjectContainer: need to update stats first\n");
		bestaction = -1;
		out.PeerCopy(scan);
		m_last_known_object = -1;
		m_orientation = 0;
		m_displacement = 0;
		return -1;
	}

	YarpPixelBGR red;
	red.r = 255;
	red.g = red.b = 0;

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

			printf ("object: %d location: %lf %lf q: %lf\n", obj, x, y, quality);

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
		bestaction = -1;
		out.PeerCopy(scan);
		m_orientation = 0;
		m_displacement = 0;
		return -1;
	}

	// if max_quality is not good enough then skip the following search.
	// if pointiness is not good enough then skip the following search.
	printf ("object is %d, improving position\n", max_obj);

	double ex, ey;
	m_locator[max_obj].GetExtent (ex, ey);
	ex *= SCALE;
	ey *= SCALE;

	// try to improve the position estimation.
	double betterx = 0, bettery = 0;
	m_locator[max_obj].ImprovedSearch (scan, ex, ey, max_x, max_y, betterx, bettery);

	printf ("object is %d, looking for orientation\n", max_obj);

	double angle = -1;
	double angle2 = -1;
	double ave = 0;
	double std = 0;
	m_locator[max_obj].GetNumberOfPoints (ave, std);

	// need to add a threshold on pointiness!
	YARPSearchRotation sr (50, 0.0);
	sr.Search (int(m_canonical_stats->m_neuron_numbers(max_obj+1)), *m_canonical, scan, betterx, bettery, ave, std, angle, angle2);
	
	// store for future use.
	m_orientation = angle;
	m_displacement = 0;

	printf ("orientation: %lf\n", angle * radToDeg);
	int x1 = betterx + cos(angle) * 40;
	int y1 = bettery + sin(angle) * 40;
	int x2 = betterx - cos(angle) * 40;
	int y2 = bettery - sin(angle) * 40;
	AddSegment (m_backp[max_obj], red, x1, y1, x2, y2);
	AddRectangle (m_backp[max_obj], red, int(betterx+.5), int(bettery+.5), int (ex/2+.5), int (ey/2+.5));

	AddCircleOutline (m_backp[max_obj], red, int(max_x+.5), int(max_y+.5), 10);
	AddCircle (m_backp[max_obj], red, int(betterx+.5), int(bettery+.5), 5);

	// return processed image.
	out.PeerCopy (m_backp[max_obj]);

	// angle is the current orientation.
	// search for the best affordance.
	const double affordance = m_canonical_stats->GetPrincipalAffordance (max_obj);
	double o1 = angle+affordance;
	double o2 = angle-affordance;
	printf ("---- object: %d, affordance: %lf, test1: %lf, test2: %lf\n", max_obj, affordance*radToDeg, o1*radToDeg, o2*radToDeg);

	if (o1 > pi/2) o1 -= pi;
	else
	if (o1 < -pi/2) o1 += pi;
	
	if (o2 > pi/2) o2 -= pi;
	else
	if (o2 < -pi/2) o2 += pi;

	double score1 = 0;
	double score2 = 0;
	int bestaction1 = m_canonical_stats->GetBestActionGeneric (o1, score1);
	int bestaction2 = m_canonical_stats->GetBestActionGeneric (o2, score2);

	printf ("---- score(s) %lf %lf\n", score1, score2);

	if (score1 < score2)
		bestaction = bestaction1;
	else
		bestaction = bestaction2;

	printf ("the best action for this object in this position is %d\n", bestaction);

	return 0;
}