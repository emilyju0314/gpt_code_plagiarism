int CImageTool::CutImageRight ( DSCC_BYTE *pImg, int wb, int h, DSCC_POINT Top, DSCC_POINT Bottom, int Type )
{//Called by CutImage() and CutBinaryImage(). Do not use it indenpendently
	if(Bottom.y == Top.y)	return -1;
	for ( int i=Top.y ; i<=Bottom.y ; i++ )
    {
        int x = (Bottom.x-Top.x)*(i-Top.y)/(Bottom.y-Top.y) + Top.x ;
		if( Type == DIB_1BIT && x < wb*8-1)
            SetHorLineToWhite ( pImg, wb, h, x+1, i, wb*8-1-(1+x), TRUE ) ;
		else if( Type == DIB_8BIT && x < wb-1)
			SetHorLineToGrayscale(pImg, wb, h, x+1, i, wb-1-(1+x), 255, TRUE);
		else if( Type == DIB_24BIT && x < wb/3-1)
			SetHorLineToColor(pImg, wb, h, x+1, i, wb/3-1-(1+x), DSCC_RGB(255, 255, 255), TRUE );
    }
    return 0 ;
}