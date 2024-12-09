void CHexEditView::AdjustColumns()
{
	int d, t, a, c, p, min;        // Current width of dffd, tab, aerial, and compare columns
	d = t = a = c = p = -1;
	int snum_d, snum_t, snum_a, snum_c, snum_p;
	snum_d = snum_t = snum_a = snum_c = snum_p = -1;

	// Get current column widths
	CHexEditSplitter *psplitter = &(GetFrame()->splitter_);
	if (pdfv_ != NULL) snum_d = psplitter->FindViewColumn(pdfv_->GetSafeHwnd());
	snum_t = psplitter->FindViewColumn(GetFrame()->ptv_->GetSafeHwnd());        // We always have a tab column since it contains the hex view
	if (pav_ != NULL) snum_a = psplitter->FindViewColumn(pav_->GetSafeHwnd());
	if (pcv_ != NULL) snum_c = psplitter->FindViewColumn(pcv_->GetSafeHwnd());
	if (ppv_ != NULL) snum_p = psplitter->FindViewColumn(ppv_->GetSafeHwnd());

	if (snum_d > -1) psplitter->GetColumnInfo(snum_d, d, min);
	if (snum_t > -1) psplitter->GetColumnInfo(snum_t, t, min);
	if (snum_a > -1) psplitter->GetColumnInfo(snum_a, a, min);
	if (snum_c > -1) psplitter->GetColumnInfo(snum_c, c, min);
	if (snum_p > -1) psplitter->GetColumnInfo(snum_p, p, min);

	// Make ideal widths slightly smaller but not less than a minimum
	bool adjust = false;
	d -= 20; if (snum_d > -1 && d < 20) { d = 20; adjust = true; }
	t -= 30; if (snum_t > -1 && t < 30) { t = 30; adjust = true; }
	a -= 10; if (snum_a > -1 && a < 10) { a = 10; adjust = true; }
	c -= 10; if (snum_c > -1 && c < 10) { c = 10; adjust = true; }
	p -= 10; if (snum_p > -1 && p < 10) { p = 10; adjust = true; }
	if (adjust)
	{
		if (snum_d > -1) psplitter->SetColumnInfo(snum_d, d, 10);
		if (snum_t > -1) psplitter->SetColumnInfo(snum_t, t, 10);
		if (snum_a > -1) psplitter->SetColumnInfo(snum_a, a, 8);
		if (snum_c > -1) psplitter->SetColumnInfo(snum_c, c, 8);
		if (snum_p > -1) psplitter->SetColumnInfo(snum_p, p, 8);
		psplitter->RecalcLayout();
	}
	if (snum_d > -1) psplitter->GetColumnInfo(snum_d, split_width_d_, min);
	if (snum_a > -1) psplitter->GetColumnInfo(snum_a, split_width_a_, min);
	if (snum_c > -1) psplitter->GetColumnInfo(snum_c, split_width_c_, min);
	if (snum_p > -1) psplitter->GetColumnInfo(snum_p, split_width_p_, min);
}