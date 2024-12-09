int CImageTool::SetLine ( DSCC_BYTE *p, int WidthInBytes, int Height, int x, int y, int Len, int bIsHorLine, int ImageType, DSCC_BYTE Gray, int bUpSideDown )
{
	if ( bIsHorLine )
	{
		if( y+Len > Height || y<0 )	return -1;
        switch ( ImageType )
        {
        case DIB_1BIT:
			{
				if( x >= WidthInBytes*8 || x<0 )
					return -1;
				return SetVerLineToWhite ( p, WidthInBytes, Height, x, y, Len, bUpSideDown ) ;
			}
        case DIB_8BIT:
            {
				if( x>=WidthInBytes || x<0 )
					return -1;
				return SetVerLineToGrayscale ( p, WidthInBytes, Height, x, y, Len, Gray, bUpSideDown ) ;
			}
		case DIB_24BIT:
			{
				if( x>=WidthInBytes/3 || x<0 )
				return SetVerLineToColor ( p, WidthInBytes, Height, x, y, Len, DSCC_RGB(255, 255, 255 ), bUpSideDown ) ; 
			}
		}
	}
    else
	{
		if( x>= Height || x<0 )
				return -1;
		switch ( ImageType )
        {
        case DIB_1BIT:
			{
				if( y+Len >= WidthInBytes*8 || y<0 )
					return -1;
				return SetHorLineToWhite ( p, WidthInBytes, Height, y, x, Len, bUpSideDown ) ;
			}
        case DIB_8BIT:
            {
				if( y+Len >= WidthInBytes || y<0 )
					return -1;
				return SetHorLineToGrayscale ( p, WidthInBytes, Height, y, x, Len, Gray, bUpSideDown ) ;
			}
		case DIB_24BIT:
			{
				if( y+Len >= WidthInBytes/3 || y<0 )
					return -1;
				return SetHorLineToColor( p, WidthInBytes, Height, y, x, Len, DSCC_RGB(255, 255, 255), bUpSideDown ) ;
			}
        }
	}
    return -1 ;
}