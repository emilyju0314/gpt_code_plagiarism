COLORREF opp_hue(COLORREF col)
{
	int hue, luminance, saturation;
	get_hls(col, hue, luminance, saturation);

	return get_rgb((hue+50)%100, luminance, saturation);
}