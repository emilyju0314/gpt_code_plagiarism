void CNavManager::Adjust(CHexEditDoc *pdoc, FILE_ADDRESS aa, FILE_ADDRESS diff)
{
	for (std::vector<nav>::iterator pv = v_.begin(); pv != v_.end(); ++pv)
	{
		if (pdoc != pv->pdoc_ || pv->end_addr_ < aa)
			continue;

		if (aa < pv->start_addr_)
			pv->start_addr_ += max(diff, aa + diff - pv->start_addr_);
		if (aa < pv->end_addr_)
			pv->end_addr_   += max(diff, aa + diff - pv->end_addr_);
	}
}