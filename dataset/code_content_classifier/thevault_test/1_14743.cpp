void SetProgressBarMsgAttributes(UINT32 ubID, SGPFont const font, UINT8 ubForeColor, UINT8 ubShadowColor)
{
	PROGRESSBAR *pCurr;
	Assert( ubID < MAX_PROGRESSBARS );
	pCurr = pBar[ ubID ];
	if( !pCurr )
		return;
	pCurr->usMsgFont            = font;
	pCurr->ubMsgFontForeColor = ubForeColor;
	pCurr->ubMsgFontShadowColor = ubShadowColor;
}