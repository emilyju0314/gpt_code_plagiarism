static BOOLEAN ApplyScrolling(INT16 sTempRenderCenterX, INT16 sTempRenderCenterY, BOOLEAN fForceAdjust, BOOLEAN fCheckOnly,
				ScrollType scrollType)
{
	// Make sure it's a multiple of 5
	sTempRenderCenterX = sTempRenderCenterX / CELL_X_SIZE * CELL_X_SIZE + CELL_X_SIZE / 2;
	sTempRenderCenterY = sTempRenderCenterY / CELL_X_SIZE * CELL_Y_SIZE + CELL_Y_SIZE / 2;

	// From render center in world coords, convert to render center in "screen" coords
	INT16 sScreenCenterX;
	INT16 sScreenCenterY;
	FromCellToScreenCoordinates(sTempRenderCenterX, sTempRenderCenterY, &sScreenCenterX, &sScreenCenterY);

	// Adjust for offset position on screen
	sScreenCenterX -=  0;
	sScreenCenterY -= 10;

	const INT16 sX_S = g_ui.m_tacticalMapCenterX;
	const INT16 sY_S = g_ui.m_tacticalMapCenterY;

	// Get corners in screen coords
	const INT16 sTopLeftWorldX = sScreenCenterX - sX_S;
	const INT16 sTopLeftWorldY = sScreenCenterY - sY_S;

	const INT16 sBottomRightWorldX = sScreenCenterX + sX_S;
	const INT16 sBottomRightWorldY = sScreenCenterY + sY_S;

	// Checking if screen shows areas outside of the map
	const BOOLEAN fOutLeft   = (gsLeftX + SCROLL_LEFT_PADDING > sTopLeftWorldX);
	const BOOLEAN fOutRight  = (gsRightX + SCROLL_RIGHT_PADDING < sBottomRightWorldX);
	const BOOLEAN fOutTop    = (gsTopY + SCROLL_TOP_PADDING >= sTopLeftWorldY);            /* top of the screen is above top of the map */
	const BOOLEAN fOutBottom = (gsBottomY + SCROLL_BOTTOM_PADDING < sBottomRightWorldY);          /* bottom of the screen is below bottom if the map */

	const int mapHeight = (gsBottomY + SCROLL_BOTTOM_PADDING) - (gsTopY + SCROLL_TOP_PADDING);
	const int screenHeight = gsVIEWPORT_END_Y - gsVIEWPORT_START_Y;

	const int mapWidth = (gsRightX + SCROLL_RIGHT_PADDING) - (gsLeftX + SCROLL_LEFT_PADDING);
	const int screenWidth = gsVIEWPORT_END_X - gsVIEWPORT_START_X;

	BOOLEAN fScrollGood = FALSE;

	if (!fOutRight && !fOutLeft && !fOutTop && !fOutBottom)
	{
		// Nothing goes outside the borders of the map.
		// Can change render center.
		fScrollGood = TRUE;
	}
	else
	{
		// Something is outside the border.
		// Let's check if we can move horizontally or vertically.

		if((scrollType == ScrollType_Horizontal)
			&& (((sTempRenderCenterX < gsRenderCenterX) && !fOutLeft)                /** moving left */
			|| ((sTempRenderCenterX > gsRenderCenterX) && !fOutRight)))            /** moving right */
		{
			// can move
			fScrollGood = TRUE;
		}

		if((scrollType == ScrollType_Vertical)
			&& (((sTempRenderCenterY < gsRenderCenterY) && !fOutTop)
			|| ((sTempRenderCenterY > gsRenderCenterY) && !fOutBottom)))
		{
			// can move
			fScrollGood = TRUE;
		}
	}

	// If in editor, anything goes
	if (gfEditMode && _KeyDown(SHIFT)) fScrollGood = TRUE;

	// Reset some UI flags
	gfUIShowExitEast  = FALSE;
	gfUIShowExitWest  = FALSE;
	gfUIShowExitNorth = FALSE;
	gfUIShowExitSouth = FALSE;

	if (!fScrollGood)
	{
		if (fForceAdjust)
		{
			INT16 newScreenCenterX = sScreenCenterX;
			INT16 newScreenCenterY = sScreenCenterY;

			if (screenHeight > mapHeight)
			{
				// printf("screen height is bigger than map height\n");
				newScreenCenterY = gsCY + (SCROLL_TOP_PADDING + SCROLL_BOTTOM_PADDING) / 2;
			}
			else if (fOutTop)
			{
				newScreenCenterY = gsTopY + SCROLL_TOP_PADDING + sY_S;
			}
			else if (fOutBottom)
			{
				newScreenCenterY = gsBottomY + SCROLL_BOTTOM_PADDING - sY_S;
			}

			if (screenWidth > mapWidth)
			{
				// printf("screen width is bigger than map width\n");
				newScreenCenterX = gsCX + (SCROLL_LEFT_PADDING + SCROLL_RIGHT_PADDING) / 2;
			}
			else if (fOutLeft)
			{
				newScreenCenterX = gsLeftX + SCROLL_LEFT_PADDING + sX_S;
			}
			else if (fOutRight)
			{
				newScreenCenterX = gsRightX + SCROLL_RIGHT_PADDING - sX_S;
			}

			INT16 sTempPosX_W;
			INT16 sTempPosY_W;
			FromScreenToCellCoordinates(newScreenCenterX, newScreenCenterY, &sTempPosX_W, &sTempPosY_W);
			sTempRenderCenterX = sTempPosX_W;
			sTempRenderCenterY = sTempPosY_W;
			fScrollGood = TRUE;
		}
		else
		{
			if (fOutRight  && gusMouseXPos >= SCREEN_WIDTH - NO_PX_SHOW_EXIT_CURS)  gfUIShowExitEast  = TRUE;
			if (fOutLeft   && gusMouseXPos <  NO_PX_SHOW_EXIT_CURS)                 gfUIShowExitWest  = TRUE;
			if (fOutTop    && gusMouseYPos <  NO_PX_SHOW_EXIT_CURS)                 gfUIShowExitNorth = TRUE;
			if (fOutBottom && gusMouseYPos >= SCREEN_HEIGHT - NO_PX_SHOW_EXIT_CURS) gfUIShowExitSouth = TRUE;
		}
	}

	if (fScrollGood && !fCheckOnly)
	{
		// Make sure it's a multiple of 5
		gsRenderCenterX = sTempRenderCenterX / CELL_X_SIZE * CELL_X_SIZE + CELL_X_SIZE / 2;
		gsRenderCenterY = sTempRenderCenterY / CELL_X_SIZE * CELL_Y_SIZE + CELL_Y_SIZE / 2;

		gsTopLeftWorldX = sTopLeftWorldX - gsLeftX;
		gsTopLeftWorldY = sTopLeftWorldY - gsTopY;

		gsBottomRightWorldX = sBottomRightWorldX - gsLeftX;
		gsBottomRightWorldY = sBottomRightWorldY - gsTopY;

		SetPositionSndsVolumeAndPanning();
	}

	return fScrollGood;
}