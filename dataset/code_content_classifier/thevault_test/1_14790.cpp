FOR_EACH(ShadowBuddies const, i, g_shadow_buddies)
	{
		if (type == i->shadow)
		{
			te.sBuddyNum = database_elem - i->first_shadow + i->first_structure;
			// Check flags and made the same, take from buddy's
			te.uiFlags |= gTileDatabase[te.sBuddyNum].uiFlags;
			break;
		}
		else if (type == i->structure)
		{
			te.sBuddyNum = database_elem - i->first_structure + i->first_shadow;
			// Set flag indicating such
			te.uiFlags |= HAS_SHADOW_BUDDY;
			break;
		}
	}