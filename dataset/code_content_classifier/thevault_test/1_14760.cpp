static void QuickButtonCallbackMButn(MOUSE_REGION* reg, INT32 reason)
{
	Assert(reg != NULL);
	GUI_BUTTON* const b = reg->GetUserPtr<GUI_BUTTON>();

	// ATE: New stuff for toggle buttons that work with new Win95 paradigm
	if (!b->Enabled())
	{
		// Should we play a sound if clicked on while disabled?
		if (b->ubSoundSchemeID &&
				reason & (MSYS_CALLBACK_REASON_LBUTTON_DWN | MSYS_CALLBACK_REASON_RBUTTON_DWN))
		{
			PlayButtonSound(b, BUTTON_SOUND_DISABLED_CLICK);
		}
		return;
	}

	bool    StateBefore = b->Clicked();
	bool    StateAfter  = true; // XXX HACK000E

	if (b->uiFlags & BUTTON_NEWTOGGLE)
	{
		if (reason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
		{
			if (!b->ubToggleButtonActivated)
			{
				b->uiFlags ^= BUTTON_CLICKED_ON;
				b->ubToggleButtonActivated = TRUE;
			}
		}
		else if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
		{
			b->ubToggleButtonActivated = FALSE;
		}
	}

	/* Kris:
	 * Set the anchored button incase the user moves mouse off region while still
	 * holding down the button, but only if the button is up.  In Win95, buttons
	 * that are already down, and anchored never change state, unless you release
	 * the mouse in the button area.
	 */
	if (b->MoveCallback == DefaultMoveCallback)
	{
		if (reason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
		{
			gpAnchoredButton = b;
			gfAnchoredState = StateBefore;
			b->uiFlags |= BUTTON_CLICKED_ON;
		}
		else if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
		{
			b->uiFlags &= ~BUTTON_CLICKED_ON;
		}
	}
	else if (b->uiFlags & BUTTON_CHECKBOX)
	{
		if (reason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
		{
			/* The check box button gets anchored, though it doesn't actually use the
			 * anchoring move callback.  The effect is different, we don't want to
			 * toggle the button state, but we do want to anchor this button so that
			 * we don't effect any other buttons while we move the mouse around in
			 * anchor mode.
			 */
			gpAnchoredButton = b;
			gfAnchoredState = StateBefore;

			/* Trick the before state of the button to be different so the sound will
			 * play properly as checkbox buttons are processed differently.
			 */
			StateBefore = !b->Clicked();
			StateAfter  = !StateBefore;
		}
		else if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
		{
			b->uiFlags ^= BUTTON_CLICKED_ON; //toggle the checkbox state upon release inside button area.
			/* Trick the before state of the button to be different so the sound will
			 * play properly as checkbox buttons are processed differently.
			 */
			StateBefore = !b->Clicked();
			StateAfter  = !StateBefore;
		}
	}

	// If there is a callback function with this button, call it
	if (b->ClickCallback != NULL)
	{
		/* Kris:  January 6, 1998
		 * Added these checks to avoid a case where it was possible to process a
		 * leftbuttonup message when the button wasn't anchored, and should have
		 * been.
		 */
		gfDelayButtonDeletion = TRUE;
		if (!(reason & MSYS_CALLBACK_REASON_LBUTTON_UP) ||
				b->MoveCallback != DefaultMoveCallback ||
				gpPrevAnchoredButton == b)
		{
			b->ClickCallback(b, reason);
		}
		gfDelayButtonDeletion = FALSE;
	}
	else if (reason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
	{
		// Otherwise, do default action with this button.
		b->uiFlags ^= BUTTON_CLICKED_ON;
	}

	if (b->uiFlags & BUTTON_CHECKBOX)
	{
		StateAfter = b->Clicked();
	}

	// Play sounds for this enabled button (disabled sounds have already been done)
	if (b->ubSoundSchemeID && b->Enabled())
	{
		if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
		{
			if (StateBefore && !StateAfter)
			{
				PlayButtonSound(b, BUTTON_SOUND_CLICKED_OFF);
			}
		}
		else if (reason & MSYS_CALLBACK_REASON_LBUTTON_DWN)
		{
			if (!StateBefore && StateAfter)
			{
				PlayButtonSound(b, BUTTON_SOUND_CLICKED_ON);
			}
		}
	}

	if (StateBefore != StateAfter)
	{
		InvalidateRegion(b->X(), b->Y(), b->BottomRightX(), b->BottomRightY());
	}

	if (gfPendingButtonDeletion) RemoveButtonsMarkedForDeletion();
}