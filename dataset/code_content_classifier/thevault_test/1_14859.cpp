static void MSYS_AddRegionToList(MOUSE_REGION* const r)
{
	/* If region seems to already be in list, delete it so we can re-insert the
	 * region. */
	MSYS_DeleteRegionFromList(r);

	MOUSE_REGION* i = MSYS_RegList;
	if (!i)
	{ // Empty list, so add it straight up.
		MSYS_RegList = r;
	}
	else
	{
		// Walk down list until we find place to insert (or at end of list)
		for (; i->next; i = i->next)
		{
			if (i->PriorityLevel <= r->PriorityLevel) break;
		}

		if (i->PriorityLevel > r->PriorityLevel)
		{ // Add after node
			r->prev = i;
			r->next = i->next;
			if (r->next) r->next->prev = r;
			i->next = r;
		}
		else
		{ // Add before node
			r->prev = i->prev;
			r->next = i;
			*(r->prev ? &r->prev->next : &MSYS_RegList) = r;
			i->prev = r;
		}
	}
}