MediaSegment::MediaSegment(const HttpMediaData& d) : flags_(0)
{
	start_ = d.st();
	end_ = d.et();
	if (d.is_last())
		set_last();
	if (d.is_pref())
		set_pref();
}