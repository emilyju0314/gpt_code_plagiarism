int CImageTool::SetHorLineToColor ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int w, DSCC_COLORREF Color, int bUpSideDown )
{
	if( bUpSideDown )
		p += (Height-1-y)*WidthInBytes + 3*x;
	else
		p += y*WidthInBytes + 3*x;
	for ( int i=0; i<w; i++)
	{
		*p = (DSCC_BYTE)(0x000000ff & Color);
		*(p+1) = (DSCC_BYTE)( (0x0000ff00 & Color) >> 8);
		*(p+2) = (DSCC_BYTE)( (0x00ff0000 & Color) >> 16);			
		p += 3;
	}
	return 0;
}