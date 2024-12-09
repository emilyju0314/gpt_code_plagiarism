int CImageTool::SetHorLineToWhite ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int w, int bUpSideDown )
{
	if( x<0 || x+w>=WidthInBytes*8 || y<0 || y>=Height )
	{
		cout<<"SetHorLineToWhite Error!"<<endl;
		return -1;
	}
    int i ;
    DSCC_BYTE mask[8] = {128,64,32,16,8,4,2,1} ;
	if( bUpSideDown )
		p += (Height-1-y)*WidthInBytes + x/8 ;
	else
		p += y*WidthInBytes + x/8 ;
    if ( x%8 > 0 )
    {
        for ( i=x%8 ; i<8 && w>0 ; i++, w-- )
            *p &= ~mask[i] ;
        p++ ;
    }
    while ( w >= 8 )
    {
        *p++ = 0 ;
        w -= 8 ;
    }
    for ( i=0 ; i<w ; i++ )
        *p &= ~mask[i] ;

    return 0 ;
}