int CaffDramMcMap :: lookup(uint64_t addr)
{
    if(m_nodeIds.size() == 1) { //if there is only one MC
	return m_nodeIds[0];
    }
    else {
	int idx = ((addr >> m_mc_shift_bits) & m_mc_selector_mask);
	assert(idx < m_nodeIds.size());
	return m_nodeIds[idx];
    }
}