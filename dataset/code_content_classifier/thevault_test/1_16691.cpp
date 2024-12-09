int CImageTool::CutImageBottom ( DSCC_BYTE *pImg, int wb, int h, DSCC_POINT Left, DSCC_POINT Right, int Type )
{//Called by CutImage() and CutBinaryImage(). Do not use it indenpendently
	if(Left.x == Right.x)	return -1;
	for ( int i=Left.x ; i<=Right.x ; i++ )
    {
        int y = (Right.y-Left.y)*(i-Left.x)/(Right.x-Left.x) + Left.y ;
        if ( y >= h-1 )	continue;
        if(Type == DIB_1BIT)
			SetVerLineToWhite ( pImg, wb, h, i, y+1, h-1-(1+y), TRUE) ;
		else if(Type == DIB_8BIT)	  
			SetVerLineToGrayscale(pImg, wb, h, i, y+1, h-1-(1+y), 255, TRUE);
		else if(Type == DIB_24BIT)
			SetVerLineToColor(pImg, wb, h, i, y+1, h-1-(1+y), DSCC_RGB(255, 255, 255), TRUE );
	}
    return 0 ;
}