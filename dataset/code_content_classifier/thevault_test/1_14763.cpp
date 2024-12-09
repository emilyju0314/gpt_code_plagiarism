static void DrawTextOnButton(const GUI_BUTTON* b)
{
	// If this button actually has a string to print
	if (b->codepoints.empty()) return;

	// Get the width and height of this button
	INT32 const width  = b->W();
	INT32 const height = b->H();

	// Compute the viewable area on this button
	SGPRect NewClip;
	NewClip.iLeft   = b->X() + 3;
	NewClip.iRight  = b->X() + width - 3;
	NewClip.iTop    = b->Y() + 2;
	NewClip.iBottom = b->Y() + height - 2;

	// Get the starting coordinates to print
	const INT32 TextX = NewClip.iLeft;
	const INT32 TextY = NewClip.iTop;

	// Get the current clipping area
	SGPRect OldClip;
	GetClippingRect(&OldClip);

	// Clip the button's viewable area to the screen
	if (NewClip.iLeft < OldClip.iLeft) NewClip.iLeft = OldClip.iLeft;

	// Are we off hte right side?
	if (NewClip.iLeft > OldClip.iRight) return;

	if (NewClip.iRight > OldClip.iRight) NewClip.iRight = OldClip.iRight;

	// Are we off the left side?
	if (NewClip.iRight < OldClip.iLeft) return;

	if (NewClip.iTop < OldClip.iTop) NewClip.iTop = OldClip.iTop;

	// Are we off the bottom of the screen?
	if (NewClip.iTop > OldClip.iBottom) return;

	if (NewClip.iBottom > OldClip.iBottom) NewClip.iBottom = OldClip.iBottom;

	// Are we off the top?
	if (NewClip.iBottom < OldClip.iTop) return;

	// Did we clip the viewable area out of existance?
	if (NewClip.iRight <= NewClip.iLeft || NewClip.iBottom <= NewClip.iTop) return;

	// Set the font printing settings to the buttons viewable area
	SetFontDestBuffer(ButtonDestBuffer, NewClip.iLeft, NewClip.iTop, NewClip.iRight, NewClip.iBottom);

	// Compute the coordinates to center the text
	INT32 yp;
	if (b->bTextYOffset == -1)
	{
		yp = TextY + (height - GetFontHeight(b->usFont)) / 2 - 1;
	}
	else
	{
		yp = b->Y() + b->bTextYOffset;
	}

	INT32 xp;
	if (b->bTextXOffset == -1)
	{
		switch (b->bJustification)
		{
			case GUI_BUTTON::TEXT_LEFT:   xp = TextX + 3; break;
			case GUI_BUTTON::TEXT_RIGHT:  xp = NewClip.iRight - StringPixLength(b->codepoints, b->usFont) - 3; break;
			default:
			case GUI_BUTTON::TEXT_CENTER: xp = TextX + (width - 6 - StringPixLength(b->codepoints, b->usFont)) / 2; break;
		}
	}
	else
	{
		xp = b->X() + b->bTextXOffset;
	}

	// print the text

	//Override the colors if necessary.
	INT16 sForeColor;
	if (b->Enabled() && b->Area.uiFlags & MSYS_MOUSE_IN_AREA && b->sForeColorHilited != -1)
	{
		sForeColor = b->sForeColorHilited;
	}
	else if (b->Clicked() && b->sForeColorDown != -1)
	{
		sForeColor = b->sForeColorDown;
	}
	else
	{
		sForeColor = b->sForeColor;
	}

	UINT8 shadow;
	if (b->Enabled() && b->Area.uiFlags & MSYS_MOUSE_IN_AREA && b->sShadowColorHilited != -1)
	{
		shadow = b->sShadowColorHilited;
	}
	else if (b->Clicked() && b->sShadowColorDown != -1)
	{
		shadow = b->sShadowColorDown;
	}
	else if (b->sShadowColor != -1)
	{
		shadow = b->sShadowColor;
	}
	else
	{
		shadow = DEFAULT_SHADOW;
	}

	SetFontAttributes(b->usFont, sForeColor, shadow);

	if (b->Clicked() && b->fShiftText)
	{
		/* Was the button clicked on? if so, move the text slightly for the illusion
		 * that the text moved into the screen. */
		xp++;
		yp++;
	}

	if (b->sWrappedWidth != -1)
	{
		UINT8 bJustified = 0;
		switch (b->bJustification)
		{
			case GUI_BUTTON::TEXT_LEFT:    bJustified = LEFT_JUSTIFIED;    break;
			case GUI_BUTTON::TEXT_RIGHT:   bJustified = RIGHT_JUSTIFIED;   break;
			case GUI_BUTTON::TEXT_CENTER:  bJustified = CENTER_JUSTIFIED;  break;
			default:                       SLOGA("DrawTextOnButton: invalid text alignment"); break;
		}
		if (b->bTextXOffset == -1)
		{
			/* Kris:
			 * There needs to be recalculation of the start positions based on the
			 * justification and the width specified wrapped width.  I was drawing a
			 * double lined word on the right side of the button to find it drawing
			 * way over to the left.  I've added the necessary code for the right and
			 * center justification.
			 */
			yp = b->Y() + 2;

			switch (b->bJustification)
			{
				case GUI_BUTTON::TEXT_RIGHT:
					xp = b->BottomRightX() - 3 - b->sWrappedWidth;
					if (b->fShiftText && b->Clicked())
					{
						xp++;
						yp++;
					}
					break;

				case GUI_BUTTON::TEXT_CENTER:
					xp = b->X() + 3 + b->sWrappedWidth / 2;
					if (b->fShiftText && b->Clicked())
					{
						xp++;
						yp++;
					}
					break;
			}
		}
		yp += b->bTextYSubOffSet;
		xp += b->bTextXSubOffSet;
		DisplayWrappedString(xp, yp, b->sWrappedWidth, 1, b->usFont, sForeColor, b->codepoints, FONT_MCOLOR_BLACK, bJustified);
	}
	else
	{
		yp += b->bTextYSubOffSet;
		xp += b->bTextXSubOffSet;
		MPrint(xp, yp, b->codepoints);
	}
	// Restore the old text printing settings
}