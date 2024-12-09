int CImageTool::SetVerLineToGrayscale ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int h, DSCC_BYTE Gray, int bUpSideDown )
{//Called by SetLine(). Do not use it independently
	if( bUpSideDown )
		p += (Height-1-y)*WidthInBytes + x ;
	else
		p += y*WidthInBytes + x ;
    for ( int i=0 ; i<h ; i++ )
	{
        *p =  Gray ;
		if( bUpSideDown )
			p -= WidthInBytes;
		else
			p += WidthInBytes;
	}
    return 0 ;
}