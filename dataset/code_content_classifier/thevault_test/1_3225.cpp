COLORREF same_hue(COLORREF col, int sat, int lum /* = -1 */)
{
	int hue, luminance, saturation;
	get_hls(col, hue, luminance, saturation);

	if (lum > -1)
		luminance = lum;
	if (sat > -1)
		saturation = sat;

	return get_rgb(hue, luminance, saturation);
}