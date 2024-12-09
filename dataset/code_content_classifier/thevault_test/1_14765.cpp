static void DefaultMoveCallback(GUI_BUTTON* btn, INT32 reason)
{
	// If the button isn't the anchored button, then we don't want to modify the button state.
	if (btn != gpAnchoredButton) return;

	if (reason & MSYS_CALLBACK_REASON_LOST_MOUSE)
	{
		if (!gfAnchoredState)
		{
			btn->uiFlags &= ~BUTTON_CLICKED_ON;
			if (btn->ubSoundSchemeID)
			{
				PlayButtonSound(btn, BUTTON_SOUND_CLICKED_OFF);
			}
		}
		InvalidateRegion(btn->X(), btn->Y(), btn->BottomRightX(), btn->BottomRightY());
	}
	else if (reason & MSYS_CALLBACK_REASON_GAIN_MOUSE)
	{
		btn->uiFlags |= BUTTON_CLICKED_ON;
		if (btn->ubSoundSchemeID)
		{
			PlayButtonSound(btn, BUTTON_SOUND_CLICKED_ON);
		}
		InvalidateRegion(btn->X(), btn->Y(), btn->BottomRightX(), btn->BottomRightY());
	}
}