FILE_ADDRESS CHexEditDoc::GetCompAddress(FILE_ADDRESS addr, bool comp2orig /* = false */)
{
	FILE_ADDRESS thisAddr = 0;          // address of of diff in this file
	FILE_ADDRESS otherAddr = 0;         // address of corresp diff in other file
	FILE_ADDRESS offset = addr;         // offset from otherAddr in other file

	const std::vector<FILE_ADDRESS> * replace_addr;
	const std::vector<FILE_ADDRESS> * replace_other;
	//const std::vector<FILE_ADDRESS> * replace_len;   // not needed

	const std::vector<FILE_ADDRESS> * insert_addr;
	const std::vector<FILE_ADDRESS> * delete_other;
	const std::vector<FILE_ADDRESS> * insert_len;   // not needed

	const std::vector<FILE_ADDRESS> * delete_addr;
	const std::vector<FILE_ADDRESS> * insert_other;
	const std::vector<FILE_ADDRESS> * delete_len;

	if (comp2orig)
	{
		replace_addr = &comp_[0].m_replace_B;
		replace_other= &comp_[0].m_replace_A;

		insert_addr  = &comp_[0].m_insert_B;
		delete_other = &comp_[0].m_delete_A;
		insert_len   = &comp_[0].m_delete_len;

		delete_addr  = &comp_[0].m_delete_B;
		insert_other = &comp_[0].m_insert_A;
		delete_len   = &comp_[0].m_insert_len;   // size of deletion in B == size of insertion in A
	}
	else
	{
		replace_addr = &comp_[0].m_replace_A;
		replace_other= &comp_[0].m_replace_B;

		insert_addr  = &comp_[0].m_insert_A;
		delete_other = &comp_[0].m_delete_B;
		insert_len   = &comp_[0].m_insert_len;

		delete_addr  = &comp_[0].m_delete_A;
		insert_other = &comp_[0].m_insert_B;
		delete_len   = &comp_[0].m_delete_len;
	}

	std::vector<FILE_ADDRESS>::const_iterator pNext = std::lower_bound(replace_addr->begin(), replace_addr->end(), addr);
	if (pNext != replace_addr->begin())
	{
		// Get info from previous entry
		int idx = (pNext - replace_addr->begin()) - 1;
		thisAddr = (*replace_addr)[idx];
		otherAddr = (*replace_other)[idx];
		offset = addr - thisAddr;
	}
	pNext = std::lower_bound(insert_addr->begin(), insert_addr->end(), addr);
	if (pNext != insert_addr->begin() && *(pNext-1) > thisAddr)
	{
		int idx = (pNext - insert_addr->begin()) - 1;
		thisAddr = (*insert_addr)[idx];
		otherAddr = (*delete_other)[idx];
		offset = (addr - thisAddr) - (*insert_len)[idx];
		if (offset < 0)
			offset = 0;
	}
	pNext = std::lower_bound(delete_addr->begin(), delete_addr->end(), addr);
	if (pNext != delete_addr->begin() && *(pNext-1) > thisAddr)
	{
		int idx = (pNext - delete_addr->begin()) - 1;
		thisAddr = (*delete_addr)[idx];
		otherAddr = (*insert_other)[idx];
		offset = (addr - thisAddr) + (*delete_len)[idx];
	}

	return otherAddr + offset;
}