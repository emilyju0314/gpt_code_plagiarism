void DefineProgressBarPanel( UINT32 ubID, UINT8 r, UINT8 g, UINT8 b,
				UINT16 usLeft, UINT16 usTop, UINT16 usRight, UINT16 usBottom )
{
	PROGRESSBAR *pCurr;
	Assert( ubID < MAX_PROGRESSBARS );
	pCurr = pBar[ ubID ];
	if( !pCurr )
		return;

	pCurr->flags |= PROGRESS_PANEL;
	pCurr->usPanelLeft = usLeft;
	pCurr->usPanelTop = usTop;
	pCurr->usPanelRight = usRight;
	pCurr->usPanelBottom = usBottom;
	pCurr->usColor = Get16BPPColor( FROMRGB( r, g, b ) );
	//Calculate the slightly lighter and darker versions of the same rgb color
	pCurr->usLtColor = Get16BPPColor( FROMRGB( (UINT8)MIN( 255, (UINT16)(r*1.33)),
						(UINT8)MIN( 255, (UINT16)(g*1.33)),
						(UINT8)MIN( 255, (UINT16)(b*1.33)) ));
	pCurr->usDkColor = Get16BPPColor( FROMRGB( (UINT8)(r*0.75), (UINT8)(g*0.75), (UINT8)(b*0.75) ) );
}