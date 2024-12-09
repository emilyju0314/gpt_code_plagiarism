void CCalcDlg::button_colour(CWnd *pp, bool enable, COLORREF normal)
{
	ASSERT(pp != NULL);

	CCalcButton *pbut = DYNAMIC_DOWNCAST(CCalcButton, pp);
	ASSERT(pbut != NULL);
	if (enable)
	{
		if (pbut->GetTextColor() != normal)
		{
			pbut->SetTextColor(normal);
			pbut->SetTextHotColor(RGB(0,0,0));   // black
			pp->Invalidate();
		}
	}
	else
	{
		if (pbut->GetTextColor() != RGB(0xC0, 0xC0, 0xC0))
		{
			pbut->SetTextColor(RGB(0xC0, 0xC0, 0xC0)); // light grey
			pbut->SetTextHotColor(RGB(0xC0, 0xC0, 0xC0));
			pp->Invalidate();
		}
	}
}