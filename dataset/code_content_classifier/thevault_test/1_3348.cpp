void CAerialView::get_colours(COLORREF clr, COLORREF & clr_dark, COLORREF & clr_light)
{
	clr_dark = clr_light = clr;         // use input as defaults
	int hh, ll, ss; get_hls(clr, hh, ll, ss);
	if (ll > 65)
		clr_dark = get_rgb(hh, 35, ss);
	else if (ll < 35)
		clr_light = get_rgb(hh, 65, ss);
	else
	{
		clr_dark = get_rgb(hh, 35, ss);
		clr_light = get_rgb(hh, 65, ss);
	}
}