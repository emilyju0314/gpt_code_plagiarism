int CImageTool::GetCharBound(CImage &Image, DSCC_POINT &TopL, DSCC_POINT &TopR, DSCC_POINT &BtmL, DSCC_POINT &BtmR)
{
	int i, w, wb, h;
	DSCC_BYTE *pImg = Image.LockRawImg(); 
	w=Image.GetWidth ();
	h=Image.GetHeight ();
	wb=Image.GetLineSizeInBytes ();
	int	ImgType = Image.GetType();

	int	bAllWhite;
    int MaxDy, MaxDx ;
	
    MaxDy = (BtmL.y - TopL.y) / 3 ;
	MaxDx = (TopR.x - TopL.x) / 3;
    for ( i=0 ; i<MaxDy ; i++ ) 
    {
 		if( TopL.y >= h-1 || TopR.y >= h-1 || TopL.y <= 0 || TopR.y <= 0)	
			break;
       if ( ImgType == DIB_1BIT)
			bAllWhite = AllWhite(pImg, wb, h, TopL, TopR);
		else if ( ImgType == DIB_8BIT)
			bAllWhite = GrayAllWhite(pImg, wb, h, TopL, TopR, 128);
		else if ( ImgType == DIB_24BIT )
			bAllWhite = ColorAllWhite(pImg, wb, h, TopL, TopR, 1, 128 );
		else
			return -1;
		if ( bAllWhite )			break ; 
		TopL.y-- ; 
		TopR.y-- ;
    }

    for ( i=0 ; i<MaxDy ; i++ )
    {
		if( BtmL.y <= 0 || BtmR.y <= 0 || BtmL.y >= h-1 || BtmR.y >= h-1)	
			break;
        if ( ImgType == DIB_1BIT)
			bAllWhite = AllWhite(pImg, wb, h, BtmL, BtmR);
		else if ( ImgType == DIB_8BIT)
			bAllWhite = GrayAllWhite(pImg, wb, h, BtmL, BtmR, 128);
		else if ( ImgType == DIB_24BIT)
			bAllWhite = ColorAllWhite(pImg, wb, h, BtmL, BtmR, 1, 128);
		else
			return -1;
		if ( bAllWhite )			break ;
        BtmL.y++ ; 
		BtmR.y++ ;
    }

	for ( i=0; i<MaxDx; i++)
	{
		if( TopL.x <= 0 || BtmL.x <= 0 || TopL.x >= w-1 || BtmL.x >= w-1 )
			break;
		if ( ImgType == DIB_1BIT)
			bAllWhite = AllWhite(pImg, wb, h, TopL, BtmL);
		else if ( ImgType == DIB_8BIT)
			bAllWhite = GrayAllWhite(pImg, wb, h, TopL, BtmL, 128);
		else if ( ImgType == DIB_24BIT)
			bAllWhite = ColorAllWhite(pImg, wb, h, TopL, BtmL, 1, 128);
		else
			return -1;
		if ( bAllWhite )			break;
		TopL.x--;
		BtmL.x--;
	}

	for ( i=0; i<MaxDx; i++)
	{
        if( TopR.x >= w-1 || BtmR.x >= w-1 || TopR.x <= 0 || BtmR.x <= 0 )
			break;
		if ( ImgType == DIB_1BIT )
			bAllWhite = AllWhite(pImg, wb, h, TopR, BtmR);
		else if ( ImgType == DIB_8BIT )
			bAllWhite = GrayAllWhite(pImg, wb, h, TopR, BtmR, 128);
		else if ( ImgType == DIB_24BIT )
			bAllWhite = ColorAllWhite(pImg, wb, h, TopR, BtmR, 1, 128);
		else	return -1;
		if ( bAllWhite )			break;
		TopR.x++;		
		BtmR.x++;
	}

	Image.UnlockRawImg ();
	return 0;
}