int CImageTool::GrayAllWhite ( DSCC_BYTE *p, int wb, int h, DSCC_POINT s, DSCC_POINT e, DSCC_BYTE Gray )
{
    if(fabs((double)(s.x - e.x)) > fabs((double)(s.y - e.y)))
	{//Hor
		int xs = min(s.x, e.x);
		int xe = max(s.x, e.x);
		int ys, ye;
		if(xs == s.x)
		{	ys = s.y ;	ye = e.y;}
		else
		{	ys = e.y;	ye = s.y;}

		int step = (xe-xs) / (abs(ye-ys)+1) ;
		if ( step == 0 )
			return FALSE ;

		int dy = (ye>ys) ? 1:-1 ;
		int x = xs;
		int y = ys;
		while ( x <= xe )
		{
			int i = 0;
			while(i<step && x+i<xe)
			{	if ( *(p+(h-1-y)*wb+x+i) < Gray)
					return FALSE ;
				i++;
			}
			x += step ;
			y += dy ;
		}
	}
	else
	{//Ver
		int ys = min(s.y, e.y);
		int ye = max(s.y, e.y);
		int xs, xe;
		if(ys == s.y)
		{	xs = s.x;	xe = e.x;}
		else
		{	xs = e.x;   xe = s.x;}
		int step = (ye-ys)/(abs(xe-xs)+1) ;
		if ( step == 0)		
			return FALSE;

		int dx = (xe>xs) ? 1:-1 ;
		int y = ys;
		int x = xs;
		while ( y<= ye)
		{
			int	i = 0;
			while(i<step && y+i<ye)
			{
				if( *(p+(h-1-y-i)*wb + x) < Gray)		return FALSE;
				i++;
			}
			y += step;
			x += dx;
		}
	}
    return TRUE ;
}