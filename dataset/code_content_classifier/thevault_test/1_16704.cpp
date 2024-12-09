int CImageTool::AllVerWhite ( DSCC_BYTE *p, int wb, int h, DSCC_POINT s, DSCC_POINT e)
{	
	int i, j, x, step;
	if(s.y > e.y)	return FALSE;
	if(abs(s.x - e.x) > e.y-s.y)	return FALSE;
	DSCC_BYTE mask[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	if(s.x == e.x )		step = e.y-s.y;
	else				
		step = (e.y-s.y)/(abs(s.x-e.x)+1);
	x = s.x;
	for(i=s.y; i<e.y-step; i+=step)
	{
		for(j=0; j<abs(step); j++)
			if( *(p+(h-1-i-j)*wb+x/8) & mask[x%8])	
				return FALSE;
		if(e.x > s.x)	x++;
		else		x--;
	}
	for(;i<=e.y; i++)
	{
		if( *(p+(h-1-i)*wb+x/8) & mask[x%8] )
			return FALSE;
	}

	return TRUE;	
}