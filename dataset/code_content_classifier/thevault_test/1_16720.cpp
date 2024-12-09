double CImage::GetBlackPixelRatio()
{
    if ( GetType() != DIB_1BIT )
        return -1 ;

    int Tbl[256], i, j ;
    DSCC_BYTE mask[8] = {1, 2, 4, 8, 16, 32, 64, 128} ;
	DSCC_BYTE rz[8]={ 0xff,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe };//Right mask

    i = Tbl[0] = 0 ;
    do {
        i++ ;
        Tbl[i] = 0 ;
        for ( j=0 ; j<8 ; j++ )
            if ( i&mask[j] )
                Tbl[i]++ ;
    } while ( i != 255 ) ;

    int w = GetWidth() ; 
    int h = GetHeight() ;

    int TotalBlackPixels = 0 ;
    DSCC_BYTE *pImg = LockRawImg() ;
    int wb = GetLineSizeInBytes() ;
    for ( i=0 ; i<h ; i++ )
    {
        DSCC_BYTE *p = pImg + i*wb ;
        for ( j=0 ; j<(w+7)/8 ; j++ )
		{
			if( j==(w+7)/8-1 )
	            TotalBlackPixels += Tbl[p[j]&rz[w%8]] ;
			else
				TotalBlackPixels += Tbl[p[j]] ;
		}
    }
    UnlockRawImg() ;
    return (double)TotalBlackPixels / ( (double)w * (double)h ) ;
}