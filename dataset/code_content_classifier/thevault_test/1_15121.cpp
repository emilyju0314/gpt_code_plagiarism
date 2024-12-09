static void ScrollBackground(INT16 sScrollXIncrement, INT16 sScrollYIncrement)
{
	if (!gfDoVideoScroll)
	{
		// Clear z-buffer
		std::fill_n(gpZBuffer, gsVIEWPORT_END_Y * SCREEN_WIDTH, LAND_Z_LEVEL);

		RenderStaticWorldRect(gsVIEWPORT_START_X, gsVIEWPORT_START_Y, gsVIEWPORT_END_X, gsVIEWPORT_END_Y, FALSE);

		FreeBackgroundRectType(BGND_FLAG_ANIMATED);
	}
	else
	{
		gsScrollXIncrement += sScrollXIncrement;
		gsScrollYIncrement += sScrollYIncrement;
	}
}