static void PositionTownMineInfoBox(PopUpBox* const box)
{
	// position the box based on x and y of the selected sector
	INT16 sX = 0;
	INT16 sY = 0;
	GetScreenXYFromMapXY(bCurrentTownMineSectorX, bCurrentTownMineSectorY, &sX, &sY);
	SGPBox const& area = GetBoxArea(box);

	// now position box - the x axis
	INT16 x = sX;
	if (x          < MapScreenRect.iLeft)  x = MapScreenRect.iLeft + 5;
	if (x + area.w > MapScreenRect.iRight) x = MapScreenRect.iRight - area.w - 5;

	// position - the y axis
	INT16 y = sY;
	if (y          < MapScreenRect.iTop)    y = MapScreenRect.iTop + 5;
	if (y + area.h > MapScreenRect.iBottom) y = MapScreenRect.iBottom - area.h - 8;

	SetBoxXY(box, x, y);
}