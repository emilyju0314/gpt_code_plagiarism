int CHexEditView::AerialViewType() const
{
	if (pav_ == NULL)
		return 0;
	else if (GetFrame()->splitter_.FindViewColumn(pav_->GetSafeHwnd()) > -1)
		return 1;
	else if (GetFrame()->ptv_->FindTab(pav_->GetSafeHwnd()) > -1)
		return 2;
	else
	{
		ASSERT(FALSE);
		return 0;
	}
}