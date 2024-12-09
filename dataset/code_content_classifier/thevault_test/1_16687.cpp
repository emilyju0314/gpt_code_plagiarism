int LocalFilter( LINE Line, ROWRUNLENGTH *RowRun, int nRun )
{
	int		i;
	int		DIST_TH = 3;

	//x = b*y + a
	double	a, b;
	GetLineParam( RowRun, nRun, a, b );
	for( i=0; i<nRun; i++ )
	{
		if( RowRun[i].bUsed == FALSE )	continue;

		int x = (int)(a + b*RowRun[i].y );
		int	dxs = RowRun[i].xs - x;
		int dxe = RowRun[i].xe - x;
		if( dxs * dxe < 0 )		continue;
		else if( min( abs(dxs), abs(dxe) ) > DIST_TH )
			RowRun[i].bUsed = FALSE;
	}
	return 0;
}