bool
CDataSourceTextFile::getAt(size_t index, const data_type **data) const
{
	// the caller will request one beyond the end, so return NULL
	if (index >= mData.size())
		*data = NULL;
	else
		*data = &mData.at(index);

	return true;
}