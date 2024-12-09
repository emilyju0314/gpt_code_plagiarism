void ZoomHistory::zoom_out()
{
	double ax, ay;
	double bx, by;
	double cx, cy;

	if( m_sp == 1 ) {
		/*
		 * restore to top-level view (show all)
		 */
		m_sp -= 1;
		tf = &m_stack[ m_sp ];
		world = tf->world;
		win = tf->win;

	} else if( m_sp > 1 ) {
		/*
		 * restore previous view, but pan to be centered where
		 * the we are currently positioned.
		 */

		ax = (world.right + world.left)/2.0;
		ay = (world.bottom + world.top)/2.0;

		m_sp -= 1;
		tf = &m_stack[ m_sp ];
		world = tf->world;
		win = tf->win;

		bx = (world.right + world.left)/2.0;
		by = (world.bottom + world.top)/2.0;

		cx = ax - bx;
		cy = ay - by;

		world.left	+= cx;
		world.top	+= cy;
		world.right	+= cx;
		world.bottom	+= cy;
		TF_Set(tf, &win, &world);
	}

}