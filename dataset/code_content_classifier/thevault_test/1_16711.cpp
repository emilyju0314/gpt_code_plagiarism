double CImageTool::GetBlackPixelRatio ( CImage &Img,  DSCC_RECT rcBound )
{//It is not optimal, should use lut, lz, rz defined in Tools.cpp
    int i, j;
    DSCC_BYTE mask[8] = {128, 64, 32, 16, 8, 4, 2, 1} ;

	int	w = Img.GetWidth();
	int h = Img.GetHeight();
	int	wb = Img.GetLineSizeInBytes();
	if( rcBound.right == 0 || rcBound.bottom == 0 )
	{
		rcBound.left = 0;
		rcBound.right = w-1;
		rcBound.top = 0;
		rcBound.bottom = h-1;
	}

	DSCC_BYTE	*pImg = Img.LockRawImg();
    int TotalBlackPixels = 0 ;
    for ( i=rcBound.top ; i<=rcBound.bottom ; i++ )
    {
        DSCC_BYTE *p = pImg + (h-1-i)*wb + rcBound.left/8 ;
		if( (rcBound.left+7)/8 == (rcBound.right+7)/8 )
			TotalBlackPixels += lut[ (*p) & lz[rcBound.left%8] & rz[rcBound.right%8] ];
		else
		{
			if( rcBound.left%8 != 0 )
			{
				TotalBlackPixels += lut[ (*p) & lz[rcBound.left%8] ];
				p++;
			}
			for ( j=(rcBound.left+7)/8 ; j<=rcBound.right/8 ; j++ )
			{
				TotalBlackPixels += lut[ *p ];
				p++;
			}
			if( rcBound.right%8 != 0 )
				TotalBlackPixels += lut[ (*p) & rz[rcBound.right%8] ];
		}
    }
	Img.UnlockRawImg();
    return (double)TotalBlackPixels / ( (double)(rcBound.right-rcBound.left+1)*(double)(rcBound.bottom-rcBound.top+1) ) ;
}