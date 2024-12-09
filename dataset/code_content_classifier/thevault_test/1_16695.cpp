int CImageTool::SetHorLineToGrayscale ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int w, DSCC_BYTE Gray, int bUpSideDown )
{//Called by SetLine(). Do not use it independently
	if( bUpSideDown )
		p += (Height-1-y)*WidthInBytes + x ;
	else
		p += y*WidthInBytes + x ;
    for ( int i=0 ; i<w ; i++ )
        *p++ = Gray ;
    return 0 ;
}