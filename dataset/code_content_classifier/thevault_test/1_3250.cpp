int CHexEditDoc::CompareDifferences(int rr /*=0*/)
{
	if (pthread4_ == NULL)
	{
		return -4;
	}

	// Protect access to shared data
	CSingleLock sl(&docdata_, TRUE);
	if (comp_state_ == SCANNING)
	{
		return -2;
	}

	ASSERT(rr >= 0 && rr < comp_.size());
	if (rr < 0 || rr >= comp_.size())
		return -1;

	ASSERT(comp_[rr].m_replace_A.size() == comp_[rr].m_replace_len.size());
	ASSERT(comp_[rr].m_insert_A.size() == comp_[rr].m_insert_len.size());
	ASSERT(comp_[rr].m_delete_A.size() == comp_[rr].m_delete_len.size());
	return comp_[rr].m_replace_A.size() + comp_[rr].m_insert_A.size() + comp_[rr].m_delete_A.size();
}