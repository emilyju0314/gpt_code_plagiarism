int CImageTool::GetBlackPixelNum ( DSCC_BYTE *p, int wb, int hh, int left, int top, int w, int h )
{//It is not optimal, should use lut, lz, rz defined in Tools.cpp
    DSCC_BYTE mask[8] = {128, 64, 32, 16, 8, 4, 2, 1 } ;
    int sum = 0 ;

    for ( int i=0 ; i<h ; i++ )
    {
        DSCC_BYTE *tp = p+(hh-1-top-i)*wb + left/8 ;
        int k = left%8 ;
        for ( int j=0 ; j<w ; j++ )
        {
            if ( *tp & mask[k++] ) sum++ ;
            if ( k == 8 ) tp++, k=0 ;
        }
    }
    return sum ;
}