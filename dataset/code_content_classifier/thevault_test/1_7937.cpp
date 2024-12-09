void ZoomHistory::zoom_in()
{
	double w, h;

	CRect rect;

	/*
	 * Create 'rect' as a 1/4 smaller rectangle inside of
	 * 'window'.
	 */
	w = (win.right - win.left) / 8.0;
	h = (win.bottom - win.top) / 8.0;

	rect.left	= (int) (win.left	+ w);
	rect.top	= (int) (win.top	+ h);
	rect.right	= (int) (win.right	- w);
	rect.bottom	= (int) (win.bottom	- h);

	zoom_in(rect);
}