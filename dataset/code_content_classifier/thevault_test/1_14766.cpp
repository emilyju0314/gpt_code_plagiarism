static void DisplayDots(UINT16 usNameX, UINT16 usNameY, UINT16 usStatX, const ST::string& pString)
{
	UINT16 usStringLength = StringPixLength(pString, AIM_M_FONT_STATIC_TEXT);
	INT16  i;
	UINT16 usPosX;

	usPosX = usStatX;
	for(i=usNameX + usStringLength; i <= usPosX; usPosX-=7)
	{
		DrawTextToScreen(".", usPosX, usNameY, 0, AIM_M_FONT_STATIC_TEXT, AIM_M_COLOR_STATIC_TEXT, FONT_MCOLOR_BLACK, LEFT_JUSTIFIED);
	}
}