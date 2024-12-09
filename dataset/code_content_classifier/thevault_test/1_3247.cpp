bool CHexEditDoc::OrigFileHasChanged()
{
	if (pfile1_ == NULL)
		return false;

	bool retval = false;

	// Use current knowledge of last change time to see if original file has changed
	if (prev_mtime_ != prev_comp_mtime_)
	{
		retval = true;
		prev_comp_mtime_ = prev_mtime_;  // keep track of last check
	}

	return retval;
}