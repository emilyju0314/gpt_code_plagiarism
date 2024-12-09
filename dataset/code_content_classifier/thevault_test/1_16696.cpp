int CImageTool::SetVerLineToColor ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int h, DSCC_COLORREF Color, int bUpSideDown )
{//COLORREF = 0x00bbggrr
	if( bUpSideDown )
		p += (Height-1-y)*WidthInBytes + 3*x;
	else
		p += y*WidthInBytes + 3*x;

	for( int i=0; i<h; i++)
	{
		*p = (DSCC_BYTE)(0x000000ff & Color);
		*(p+1) = (DSCC_BYTE)( (0x0000ff00 & Color) >> 8);
		*(p+2) = (DSCC_BYTE)( (0x00ff0000 & Color) >> 16);			
		if( bUpSideDown ) 
			p -= WidthInBytes;
		else
			p += WidthInBytes;
	}
	return 0;
}