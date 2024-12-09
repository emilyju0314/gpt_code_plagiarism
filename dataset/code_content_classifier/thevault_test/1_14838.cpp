void RectangleDraw(BOOLEAN const fClip, int const XStart, int const YStart, int const XEnd, int const YEnd, short const Color, UINT16* const ScreenPtr)
{
	LineDraw(fClip, XStart, YStart, XEnd,   YStart, Color, ScreenPtr);
	LineDraw(fClip, XStart, YEnd,   XEnd,   YEnd,   Color, ScreenPtr);
	LineDraw(fClip, XStart, YStart, XStart, YEnd,   Color, ScreenPtr);
	LineDraw(fClip, XEnd,   YStart, XEnd,   YEnd,   Color, ScreenPtr);
}