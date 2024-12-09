static void DrawQuickButton(const GUI_BUTTON* b)
{
	const BUTTON_PICS* const pics = b->image;

	INT32 UseImage = 0;
	if (b->Enabled())
	{
		if (b->Clicked())
		{
			// Is the mouse over this area, and we have a hilite image?
			if (b->Area.uiFlags & MSYS_MOUSE_IN_AREA &&
					gfRenderHilights &&
					pics->OnHilite != -1)
			{
				UseImage = pics->OnHilite;
			}
			else if (pics->OnNormal != -1)
			{
				UseImage = pics->OnNormal;
			}
		}
		else
		{
			// Is the mouse over the button, and do we have hilite image?
			if (b->Area.uiFlags & MSYS_MOUSE_IN_AREA &&
					gfRenderHilights &&
					pics->OffHilite != -1)
			{
				UseImage = pics->OffHilite;
			}
			else if (pics->OffNormal != -1)
			{
				UseImage = pics->OffNormal;
			}
		}
	}
	else if (pics->Grayed != -1)
	{
		// Button is diabled so use the "Grayed-out" image
		UseImage = pics->Grayed;
	}
	else
	{
		UseImage = pics->OffNormal;
		switch (b->bDisabledStyle)
		{
			case GUI_BUTTON::DISABLED_STYLE_DEFAULT:
				gbDisabledButtonStyle = !b->codepoints.empty() ?
					GUI_BUTTON::DISABLED_STYLE_SHADED :
					GUI_BUTTON::DISABLED_STYLE_HATCHED;
				break;

			case GUI_BUTTON::DISABLED_STYLE_HATCHED:
			case GUI_BUTTON::DISABLED_STYLE_SHADED:
				gbDisabledButtonStyle = b->bDisabledStyle;
				break;
		}
	}

	BltVideoObject(ButtonDestBuffer, pics->vobj, UseImage, b->X(), b->Y());
}