COLORREF add_contrast(COLORREF col, COLORREF bg_col)
{
	int hue, luminance, saturation;
	get_hls(col, hue, luminance, saturation);

	int bg_hue, bg_luminance, bg_saturation;
	get_hls(bg_col, bg_hue, bg_luminance, bg_saturation);

	if (bg_luminance >= 50 && luminance > bg_luminance - 25)
	{
		// Decrease luminance to increase contrast
		luminance = bg_luminance - 25;
	}
	else if (bg_luminance < 50 && luminance < bg_luminance + 25)
	{
		// Increase luminance to increase contrast
		luminance = bg_luminance + 25;
	}
	assert(luminance <= 100 && luminance >= 0);

	// Make colour the same shade as col but less "bright"
	return get_rgb(hue, luminance, saturation);
}