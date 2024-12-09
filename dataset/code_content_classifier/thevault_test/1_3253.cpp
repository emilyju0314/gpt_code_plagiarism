std::pair<FILE_ADDRESS, FILE_ADDRESS> CHexEditDoc::GetFirstDiffAll()
{
	std::pair<FILE_ADDRESS, FILE_ADDRESS> retval;
	retval.first = LLONG_MAX;                          // default value indicates "not found"

	if (pthread4_ == NULL) return retval;              // no background compare is happening

	CSingleLock sl(&docdata_, TRUE);
	if (comp_state_ != WAITING) return retval;         // not finished

	for (int rr = 0; rr < comp_.size(); ++rr)
	{
		if (!comp_[rr].m_replace_A.empty())
		{
			retval.first  = comp_[rr].m_replace_A[0];
			retval.second = comp_[rr].m_replace_len[0];
		}

		if (!comp_[rr].m_insert_A.empty())
		{
			if (comp_[rr].m_insert_A[0] < retval.first)
			{
				retval.first = comp_[rr].m_insert_A[0];
				retval.second = - comp_[rr].m_insert_len[0];        // use -ve length to indicate insertion
			}
		}

		if (!comp_[rr].m_delete_A.empty())
		{
			if (comp_[rr].m_delete_A[0] < retval.first)
			{
				retval.first = comp_[rr].m_delete_A[0];
				retval.second = 0;                        // use zero length to indicate a deletion
			}
		}
	}

	if (retval.first == LLONG_MAX)
		retval.first = -1;           // signal not found
	return retval;
}