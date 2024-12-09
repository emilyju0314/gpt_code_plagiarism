GBool BitmapOutputDev::beginType3Char(GfxState *state, double x, double y,
			     double dx, double dy,
			     CharCode code, Unicode *u, int uLen)
{
    msg("<debug> beginType3Char");
    /* call gfxdev so that it can generate "invisible" characters
       on top of the actual graphic content, for text extraction */
    return gfxdev->beginType3Char(state, x, y, dx, dy, code, u, uLen);
}