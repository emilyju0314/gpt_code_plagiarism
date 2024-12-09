int CImageTool::SetVerLineToBlack ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int h, int bUpSideDown )
{//Called by SetLine(). Do not use it independently
    DSCC_BYTE mask = 128>>(x%8) ;
	if( bUpSideDown )
		p += (Height-1-y)*WidthInBytes + x/8 ;
	else
		p += y*WidthInBytes + x/8 ;
    for ( int i=0 ; i<h ; i++, p-=WidthInBytes )
        *p |= mask ;
    return 0 ;
}