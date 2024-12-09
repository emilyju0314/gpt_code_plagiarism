static void DrawHorizontalRun(UINT16** const ScreenPtr, int const XAdvance, int const RunLength, int const Color)
{
	UINT16* WorkingScreenPtr = *ScreenPtr;

	for (int i = 0; i < RunLength; i++)
	{
		*WorkingScreenPtr = Color;
		WorkingScreenPtr += XAdvance;
	}
	/* Advance to the next scan line */
	WorkingScreenPtr += giImageWidth >> 1;
	*ScreenPtr = WorkingScreenPtr;
}