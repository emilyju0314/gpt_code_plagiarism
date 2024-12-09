bool CAerialView::update_tip(int elt)
{
	tip_elt_ = elt;
	tip_.Clear();
	FILE_ADDRESS addr = FILE_ADDRESS(elt)*GetDocument()->GetBpe();

	ASSERT(phev_ != NULL);
	if (phev_->DecAddresses())
	{
		// Show dec then hex address in the tip
		dec_addr_tip(addr);
		hex_addr_tip(addr);
	}
	else
	{
		// Show hex then decimal address in the tip
		hex_addr_tip(addr);
		dec_addr_tip(addr);
	}

	tip_.SetAlpha(theApp.tip_transparency_);
	return true;
}