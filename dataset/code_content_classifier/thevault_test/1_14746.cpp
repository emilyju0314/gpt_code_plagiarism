void RenderProgressBar( UINT8 ubID, UINT32 uiPercentage )
{
	static UINT32 uiLastTime = 0;
	UINT32 uiCurTime = GetJA2Clock();
	double rActual;
	PROGRESSBAR *pCurr=NULL;
	//UINT32 r, g;

	Assert( ubID < MAX_PROGRESSBARS );
	pCurr = pBar[ubID];

	if( pCurr == NULL )
		return;

	if( pCurr )
	{
		rActual = pCurr->rStart+(pCurr->rEnd-pCurr->rStart)*uiPercentage*0.01;

		if( rActual - pCurr->rLastActual < 0.01 )
		{
			return;
		}

		pCurr->rLastActual = ( DOUBLE )( ( INT32)( rActual * 100 ) * 0.01 );

		INT32 const x   = pCurr->pos.x;
		INT32 const y   = pCurr->pos.y;
		INT32 const w   = pCurr->pos.w;
		INT32 const h   = pCurr->pos.h;
		INT32 const end = (INT32)(x + 2.0 + rActual * (w - 4));
		if (end < x + 2 || x + w - 2 < end) return;
		if (pCurr->flags & PROGRESS_LOAD_BAR)
		{
			ColorFillVideoSurfaceArea(FRAME_BUFFER, x, y, end, y + h, Get16BPPColor(pCurr->fill_colour));
		}
		else
		{
			//Border edge of the progress bar itself in gray
			ColorFillVideoSurfaceArea( FRAME_BUFFER,
				x, y, x + w, y + h,
				Get16BPPColor(FROMRGB(160, 160, 160)) );
			//Interior of progress bar in black
			ColorFillVideoSurfaceArea( FRAME_BUFFER,
				x + 2, y + 2, x + w - 2, y + h - 2,
				Get16BPPColor(FROMRGB(  0,   0,   0)) );
			ColorFillVideoSurfaceArea(FRAME_BUFFER,	x + 2, y + 2, end, y + h - 2, Get16BPPColor(FROMRGB(72 , 155, 24)));
		}
		InvalidateRegion(x, y, x + w, y + h);
		ExecuteBaseDirtyRectQueue();
		EndFrameBufferRender();
		RefreshScreen();
	}

	// update music here
	if( uiCurTime > ( uiLastTime + 200 ) )
	{
		MusicPoll();
		uiLastTime = GetJA2Clock();
	}
}