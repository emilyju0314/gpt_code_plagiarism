static void DrawButtonFromPtr(GUI_BUTTON* b)
{
	// Draw the appropriate button according to button type
	gbDisabledButtonStyle = GUI_BUTTON::DISABLED_STYLE_NONE;
	switch (b->uiFlags & BUTTON_TYPES)
	{
		case BUTTON_QUICK:    DrawQuickButton(b);    break;
		case BUTTON_GENERIC:  DrawGenericButton(b);  break;
		case BUTTON_CHECKBOX: DrawCheckBoxButton(b); break;

		case BUTTON_HOT_SPOT:
			return; // hotspots don't have text, but if you want to, change this to a break!
	}
	if (b->icon)   DrawIconOnButton(b);
	if (!b->codepoints.empty()) DrawTextOnButton(b);
	/* If the button is disabled, and a style has been calculated, then draw the
	 * style last.
	 */
	switch (gbDisabledButtonStyle)
	{
		case GUI_BUTTON::DISABLED_STYLE_HATCHED: DrawHatchOnButton(b); break;
		case GUI_BUTTON::DISABLED_STYLE_SHADED:  DrawShadeOnButton(b); break;
	}
}