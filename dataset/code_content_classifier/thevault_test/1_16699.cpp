int CImageTool::SetVerLineToWhite ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int h, int bUpSideDown )
{//Called by SetLine(). Do not use it independently
	if( x<0 || x>=WidthInBytes*8 || y<0 || y+h>Height )
	{
		cout<<"SetVerLineToWhite Error!"<<endl;
		return -1;
	}
    DSCC_BYTE mask = 128>>(x%8) ;
	if( bUpSideDown )
		p += (Height-1-y)*WidthInBytes + x/8 ;
	else
		p += y*WidthInBytes + x/8 ;
    for ( int i=0 ; i<h ; i++ )
	{
        *p &= ~mask ;
		if( bUpSideDown )
			p -= WidthInBytes;
		else
			p += WidthInBytes;
	}
    return 0 ;
}