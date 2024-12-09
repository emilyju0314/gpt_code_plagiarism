void CHexEditView::invalidate_addr_range(FILE_ADDRESS start_addr, FILE_ADDRESS end_addr)
{
	if (pav_ != NULL)
		pav_->InvalidateRange(start_addr, end_addr);
	invalidate_hex_addr_range(start_addr, end_addr);
}