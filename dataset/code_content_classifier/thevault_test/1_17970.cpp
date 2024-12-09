GBool FullBitmapOutputDev::beginType3Char(GfxState *state, double x, double y,
			     double dx, double dy,
			     CharCode code, Unicode *u, int uLen)
{
    msg("<debug> beginType3Char");
    return rgbdev->beginType3Char(state, x, y, dx, dy, code, u, uLen);
}