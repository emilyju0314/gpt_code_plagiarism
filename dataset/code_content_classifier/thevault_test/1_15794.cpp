int updateScrollText(FrameCanvas *canvas, const Font &font, int x, const char *str) {
	int length = DrawText(canvas, font, x, 0 + font.baseline(), color, &bg_color, str, 0);

	if (--x + length < 0)
		x = x_orig;

	return x;
}