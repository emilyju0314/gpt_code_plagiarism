int LocalFilter( LINE Line, COLRUNLENGTH *ColRun, int nRun )
{
	int		i;
	int		DIST_TH = 3;

	//y = b*x + a
	double	a, b;
	GetLineParam( ColRun, nRun, a, b );
	for( i=0; i<nRun; i++ )
	{
		if( ColRun[i].bUsed == FALSE )	continue;

		int y = (int)(a + b*ColRun[i].x );
		int	dys = ColRun[i].ys - y;
		int dye = ColRun[i].ye - y;
		if( dys * dye < 0 )		continue;
		else if( min( abs(dys), abs(dye) ) > DIST_TH )
			ColRun[i].bUsed = FALSE;
	}
	return 0;
}