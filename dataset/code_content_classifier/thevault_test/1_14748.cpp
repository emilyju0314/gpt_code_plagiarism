bool AddWallToStructLayer(INT32 const map_idx, UINT16 const idx, bool const replace)
{
	// Get orientation of piece we want to add
	UINT16 const wall_orientation = GetWallOrientation(idx);

	// Look through all objects and Search for orientation
	bool  insert_found = false;
	bool  roof_found   = false;
	UINT8 roof_level   = 0;
	UINT8 level        = 0;
	for (LEVELNODE* i = gpWorldLevelData[map_idx].pStructHead; i; ++level, i = i->pNext)
	{
		if (i->uiFlags & LEVELNODE_CACHEDANITILE) continue;
		UINT16 const check_wall_orient = GetWallOrientation(i->usIndex);

		/* Kris: If placing a new wall which is at right angles to the current wall,
		 * then we insert it. */
		if (check_wall_orient > wall_orientation)
		{
			if (((wall_orientation  == INSIDE_TOP_RIGHT || wall_orientation  == OUTSIDE_TOP_RIGHT) &&
					(check_wall_orient == INSIDE_TOP_LEFT  || check_wall_orient == OUTSIDE_TOP_LEFT)) ||
					((wall_orientation  == INSIDE_TOP_LEFT  || wall_orientation  == OUTSIDE_TOP_LEFT) &&
					(check_wall_orient == INSIDE_TOP_RIGHT || check_wall_orient == OUTSIDE_TOP_RIGHT)))
			{
				insert_found = true;
			}
		}

		UINT32 const check_type = GetTileType(i->usIndex);
		if (FIRSTROOF <= check_type && check_type <= LASTROOF)
		{
			roof_found = true;
			roof_level = level;
		}

		/* Kris: We want to check for walls being parallel to each other.  If so,
		 * then we we want to replace it.  This is because of an existing problem
		 * with say, INSIDE_TOP_LEFT and OUTSIDE_TOP_LEFT walls coexisting. */
		if (((wall_orientation  == INSIDE_TOP_RIGHT || wall_orientation  == OUTSIDE_TOP_RIGHT) &&
			(check_wall_orient == INSIDE_TOP_RIGHT || check_wall_orient == OUTSIDE_TOP_RIGHT)) ||
			((wall_orientation  == INSIDE_TOP_LEFT  || wall_orientation  == OUTSIDE_TOP_LEFT) &&
			(check_wall_orient == INSIDE_TOP_LEFT  || check_wall_orient == OUTSIDE_TOP_LEFT)))
		{
			// Same, if replace, replace here
			return replace ? ReplaceStructIndex(map_idx, i->usIndex, idx) : false;
		}
	}

	// Check if we found an insert position, otherwise set to head
	if (insert_found)
	{
		AddStructToHead(map_idx, idx);
	}
	else if (roof_found) // Make sure it's ALWAYS after the roof (if any)
	{
		InsertStructIndex(map_idx, idx, roof_level);
	}
	else
	{
		AddStructToTail(map_idx, idx);
	}

	ResetSpecificLayerOptimizing(TILES_DYNAMIC_STRUCTURES);
	return true;
}