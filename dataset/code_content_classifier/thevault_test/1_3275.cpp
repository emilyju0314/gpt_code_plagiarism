int CHexEditDoc::GetBookmarkAt(FILE_ADDRESS pos)
{
	std::vector<FILE_ADDRESS>::const_iterator pp = std::find(bm_posn_.begin(), bm_posn_.end(), pos);
	if (pp != bm_posn_.end())
		return bm_index_[pp-bm_posn_.begin()];
	else
		return -1;
}