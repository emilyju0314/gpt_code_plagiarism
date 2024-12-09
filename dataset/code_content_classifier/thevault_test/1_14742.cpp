void SetProgressBarTitle(UINT32 ubID, const ST::string& str, SGPFont font, UINT8 ubForeColor, UINT8 ubShadowColor)
{
	PROGRESSBAR *pCurr;
	Assert( ubID < MAX_PROGRESSBARS );
	pCurr = pBar[ ubID ];
	if( !pCurr )
		return;
	pCurr->title = str;
	pCurr->usTitleFont = font;
	pCurr->ubTitleFontForeColor = ubForeColor;
	pCurr->ubTitleFontShadowColor = ubShadowColor;
}