int CImageTool::CutImageLeft ( DSCC_BYTE *pImg, int wb, int h, DSCC_POINT Top, DSCC_POINT Bottom, int Type )
{//Called by CutImage() and CutBinaryImage(). Do not use it indenpendently
	if(Bottom.y == Top.y)	return -1;
	for ( int i=Top.y ; i<=Bottom.y ; i++ )
    {
        int x = (Bottom.x-Top.x)*(i-Top.y)/(Bottom.y-Top.y) + Top.x ;
        if ( x < 0 )	continue;
		if ( Type == DIB_1BIT )
            SetHorLineToWhite ( pImg, wb, h, 0, i, x, TRUE ) ;
		else if(Type == DIB_8BIT )
			SetHorLineToGrayscale(pImg, wb, h, 0, i, x, 255, TRUE);
		else if(Type == DIB_24BIT )
			SetHorLineToColor(pImg, wb, h, 0, i, x, DSCC_RGB(255, 255, 255), TRUE);
    }
    return 0 ;
}