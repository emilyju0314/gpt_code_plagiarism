static void QuickButtonCallbackMMove(MOUSE_REGION* reg, INT32 reason)
{
	Assert(reg != NULL);
	GUI_BUTTON* const b = reg->GetUserPtr<GUI_BUTTON>();

	// ATE: New stuff for toggle buttons that work with new Win95 paradigm
	if (b->uiFlags & BUTTON_NEWTOGGLE &&
			reason & MSYS_CALLBACK_REASON_LOST_MOUSE &&
			b->ubToggleButtonActivated)
	{
		b->uiFlags ^= BUTTON_CLICKED_ON;
		b->ubToggleButtonActivated = FALSE;
	}

	if (!b->Enabled()) return;

	if (reason & (MSYS_CALLBACK_REASON_LOST_MOUSE | MSYS_CALLBACK_REASON_GAIN_MOUSE))
	{
		b->uiFlags |= BUTTON_DIRTY;
	}

	if (b->MoveCallback) b->MoveCallback(b, reason);
}