std::pair<FILE_ADDRESS, FILE_ADDRESS> CHexEditDoc::GetLastDiffAll()
{
	std::pair<FILE_ADDRESS, FILE_ADDRESS> retval;
	retval.first = -1;

	if (pthread4_ == NULL) return retval;

	CSingleLock sl(&docdata_, TRUE);
	if (comp_state_ != WAITING) return retval;         // not finished

	for (int rr = 0; rr < comp_.size(); ++rr)
	{
		if (!comp_[rr].m_replace_A.empty())
		{
			retval.first  = comp_[rr].m_replace_A.back();
			retval.second = comp_[rr].m_replace_len.back();
		}

		if (!comp_[rr].m_insert_A.empty())
		{
			if (comp_[rr].m_insert_A.back() > retval.first)
			{
				retval.first = comp_[rr].m_insert_A.back();
				retval.second = - comp_[rr].m_insert_len.back();        // use -ve length to indicate insertion
			}
		}

		if (!comp_[rr].m_delete_A.empty())
		{
			if (comp_[rr].m_delete_A.back() > retval.first)
			{
				retval.first = comp_[rr].m_delete_A.back();
				retval.second = 0;                        // use zero length to indicate a deletion
			}
		}
	}

	return retval;
}