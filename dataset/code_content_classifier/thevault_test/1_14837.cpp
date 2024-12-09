static void DrawVerticalRun(UINT16** const ScreenPtr, int const XAdvance, int const RunLength, int const Color)
{
	UINT16* WorkingScreenPtr = *ScreenPtr;

	int const pitch = giImageWidth >> 1;
	for (int i = 0; i < RunLength; i++)
	{
		*WorkingScreenPtr = Color;
		WorkingScreenPtr += pitch;
	}
	/* Advance to the next column */
	WorkingScreenPtr += XAdvance;
	*ScreenPtr = WorkingScreenPtr;
}