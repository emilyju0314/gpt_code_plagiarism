static void RemoveGroupFromList(GROUP* const g)
{
	for (GROUP** i = &gpGroupList; *i != NULL; i = &(*i)->next)
	{
		if (*i != g) continue;

		// Found the group, so now remove it.
		*i = g->next;

		// Clear the unique group ID
		const UINT32 index = g->ubGroupID / 32;
		const UINT32 bit   = g->ubGroupID % 32;
		const UINT32 mask  = 1 << bit;
		Assert(uniqueIDMask[index] & mask);
		uniqueIDMask[index] &= ~mask;

		delete g;
		return;
	}
	SLOGA("Trying to remove a strategic group that isn't in the list!");
}