int CImageTool::AllWhite ( DSCC_BYTE *p, int wb, int h, DSCC_POINT s, DSCC_POINT e )
{
	if ( abs(s.x - e.x) > abs(s.y - e.y) )
	{
		int w = e.x-s.x+1 ;
		if ( w <= 0 )
			return FALSE ;

		int step = w / (abs(e.y-s.y)+1) ;
		if ( step == 0 )
			return FALSE ;

		int dy = (e.y>s.y) ? 1:-1 ;
		int x = s.x ;
		int y = s.y ;
		while ( x <= e.x )
		{
			if ( !AllHorWhite(p, wb, h, x, y, min((long)step, e.x-x+1)) )
				return FALSE ;
			x += step ;
			y += dy ;
		}
		return TRUE ;
	}
	else
		return AllVerWhite(p, wb, h, s, e);
}