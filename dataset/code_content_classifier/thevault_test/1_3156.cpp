void CHexEditView::check_error()
{
	if (GetDocument()->HasSectorErrors())
	{
		// turn on sector display so user can see which sector(s) had errors
		display_.borders = 1;

		if (!errors_mentioned_)
		{
			TaskMessageBox("Read Error",
				"One or more bad sectors were reported when attempting to read from the device.");
			errors_mentioned_ = true;
		}
	}
}