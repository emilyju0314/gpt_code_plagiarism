void CHexEditApp::display_options(int display_page /* = -1 */, BOOL must_show_page /*=FALSE*/)
{
	// Construct property sheet + its pages
	COptSheet optSheet(_T("HexEdit Options"), display_page, must_show_page);

	// Load current settings into the property sheet
	get_options(optSheet.val_);

	optSheet.m_psh.dwFlags &= ~(PSH_HASHELP);      // Turn off help button
	optSheet.DoModal();
	// Note: updating the options in response to DoModal returning IDOK is
	// not a good idea as then the Apply button does nothing.
}