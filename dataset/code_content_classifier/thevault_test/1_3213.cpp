int CHexEditView::TemplateViewType() const
{
	if (pdfv_ == NULL)
		return 0;
	else if (GetFrame()->splitter_.FindViewColumn(pdfv_->GetSafeHwnd()) > -1)
		return 1;
	else if (GetFrame()->ptv_->FindTab(pdfv_->GetSafeHwnd()) > -1)
		return 2;
	else
	{
		ASSERT(FALSE);
		return 0;
	}
}