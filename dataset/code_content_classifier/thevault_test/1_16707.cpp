int CImageTool::ColorAllWhite ( DSCC_BYTE *p, int wb, int h, DSCC_POINT s, DSCC_POINT e, int Channel, DSCC_BYTE Gray )
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

		int dy;
		if(ye>ys)			dy = 1;
		else if( ye< ys)	dy = -1;
		else				dy = 0;
		int x = xs;
		int y = ys;
		while ( x <= xe )
		{
			if( y<0 || y>=h )	
				return FALSE;
			if( x<0 || x>=wb)	
				return FALSE;
			int i = 0;
			while(i<step && x+i<xe)
			{	if ( *(p+(h-1-y)*wb+3*(x+i)+Channel) < Gray)
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

		int dx;
		if(xe>xs)		dx = 1;
		else if( xe<xe) dx = -1;
		else			dx = 0;
		int y = ys;
		int x = xs;
		while ( y<= ye)
		{
			if( y<0 || y>=h )
				return FALSE;
			if( x<0 || x>=wb)
				return FALSE;
			int	i = 0;
			while(i<step && y+i<ye)
			{
				if( *(p+(h-1-y-i)*wb + 3*x + Channel) < Gray)
					return FALSE;
				i++;
			}
			y += step;
			x += dx;
		}
	}
    return TRUE ;
}