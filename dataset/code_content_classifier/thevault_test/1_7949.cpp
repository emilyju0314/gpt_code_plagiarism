static void create_barrier_ellipse(UNIVERSE *u)
{
	double Pos_angle = 0.0;
	double Start_angle = 0.0;
	double End_angle = 360.0;
	double Rad = 0.017453292519943295769237;

	double delta;
	double center_x, center_y;	// center
	double major, minor;		// major axis and minor axis size

	double cosp, sinp;		// angles
	double cosa, sina;		// angles
	double alpha;			// used in polar coordinates
	double r;			// radius used in polar coords
	double denom;			// help variable
	double xell, yell;		// points of not rotated ellipse
	double x, y;			// each point of ellipse

	int curr_point_x, curr_point_y;
	int prev_point_x, prev_point_y;
	int first_point_x, first_point_y;

	bool first;
	double curve_angle;

	delta = 1.0;

	center_x = (u->width) / 2.0;
	center_y = (u->height) / 2.0;

	major = (u->width) / 2.0;
	minor = (u->height) / 2.0;

	cosp = cos( Pos_angle * Rad );
	sinp = sin( Pos_angle * Rad );

	first = true;
	alpha = Start_angle;
	curve_angle = 0.0;

	while( alpha <= End_angle ) {

		cosa = cos( alpha * Rad );
		sina = sin( alpha * Rad );
		denom = (minor*cosa * minor*cosa + major*sina * major*sina);
		if( denom == 0.0 ) {
			r = 0.0;
		} else {
			r = sqrt( minor*major * minor*major / denom );
		}

		xell = r * cosa;
		yell = r * sina;

		x = (xell * cosp - yell * sinp  + center_x);
		y = (xell * sinp + yell * cosp  + center_y);

		curr_point_x = ROUND(x);
		curr_point_y = ROUND(y);

		if( ! first ) {
			create_barrier_line(u, prev_point_x, prev_point_y, curr_point_x, curr_point_y);
		} else {
			first = false;
			first_point_x = curr_point_x;
			first_point_y = curr_point_y;
		}

		prev_point_x = curr_point_x;
		prev_point_y = curr_point_y;

		alpha = alpha + delta;

		curve_angle = curve_angle + 6;
		if( curve_angle > 360.0 ) {
			curve_angle = 0.0;
		}
	}

	create_barrier_line(u, prev_point_x, prev_point_y, first_point_x, first_point_y);
}