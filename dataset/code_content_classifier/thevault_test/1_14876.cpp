static UINT8 AddGroupToList(GROUP* const g)
{
	// First, find a unique ID
	for (UINT8 id = 0; ++id;)
	{
		const UINT32 index = id / 32;
		const UINT32 bit   = id % 32;
		const UINT32 mask  = 1 << bit;
		if (uniqueIDMask[index] & mask) continue;

		// Found a free id
		g->ubGroupID         = id;
		uniqueIDMask[index] |= mask;

		// Append group to list
		GROUP** i = &gpGroupList;
		while (*i != NULL) i = &(*i)->next;
		*i = g;

		return id;
	}
	throw std::runtime_error("Out of group IDs");
}