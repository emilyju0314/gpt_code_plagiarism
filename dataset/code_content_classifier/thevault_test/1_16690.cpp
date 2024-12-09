int CImageTool::CutImageTop ( DSCC_BYTE *pImg, int wb, int h, DSCC_POINT Left, DSCC_POINT Right, int Type )
{//Called by CutImage() and CutBinaryImage(). Do not use it indenpendently
	if(Right.x == Left.x)	return -1;
	for ( int i=Left.x ; i<=Right.x ; i++ )
	{
		int y = (Right.y-Left.y)*(i-Left.x)/(Right.x-Left.x) + Left.y ;
		if ( y <= 0 )	continue;
		if ( Type == DIB_1BIT )
			SetVerLineToWhite ( pImg, wb, h, i, 0, y, TRUE) ;
		else if( Type == DIB_8BIT )
			SetVerLineToGrayscale(pImg, wb, h, i, 0, y, 255, TRUE);
		else if( Type == DIB_24BIT )
			SetVerLineToColor ( pImg, wb, h, i, 0, y, DSCC_RGB(255, 255, 255), TRUE);
	}
    return 0 ;
}