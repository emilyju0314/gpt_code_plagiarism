void PixelDraw(const BOOLEAN fClip, const INT32 xp, const INT32 yp, const INT16 sColor, UINT16* const pScreen)
{
	if (fClip && !ClipPoint(xp, yp)) return;

	pScreen[yp * (giImageWidth >> 1) + xp] = sColor;
}