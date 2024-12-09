int CNavManager::pos_offset()
{
	ASSERT(pos_ >= -1 && pos_ < int(v_.size()));
	if (pos_ == -1 ||
		!is_open_view(v_[pos_].pdoc_, v_[pos_].pview_) ||
		GetView() != v_[pos_].pview_)
	{
		return -1;
	}

	FILE_ADDRESS start, end;
	v_[pos_].pview_->GetSelAddr(start, end);
	if (start != v_[pos_].start_addr_ || end != v_[pos_].end_addr_)
		return 0;
	else
		return -1;
}