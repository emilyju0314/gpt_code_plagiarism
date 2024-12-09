COLORREF tone_down(COLORREF col, COLORREF bg_col, double amt /* = 0.75*/)
{
	int hue, luminance, saturation;
	get_hls(col, hue, luminance, saturation);

	int bg_hue, bg_luminance, bg_saturation;
	get_hls(bg_col, bg_hue, bg_luminance, bg_saturation);

	int diff = bg_luminance - luminance;

	// If toning "up" make sure that there is some change in the colour
	if (diff == 0 && amt < 0.0)
		diff = luminance > 50 ? 1 : -1;
	luminance += int(diff*amt);
	if (luminance > 100)
		luminance = 100;
	else if (luminance < 0)
		luminance = 0;

	// Make colour the same shade as col but less "bright"
	return get_rgb(hue, luminance, saturation);
}