UINT16 SearchForRoofType(UINT32 const map_idx)
{
	for (INT16 radius = 0; radius != 32; ++radius)
	{
		for (INT16 y = -radius; y <= radius; ++y)
		{
			for (INT16 x = -radius; x <= radius; ++x)
			{
				if (ABS(x) != radius && ABS(y) != radius) continue;

				GridNo const grid_no = map_idx + y * WORLD_COLS + x;
				if (!GridNoOnVisibleWorldTile(grid_no)) continue;

				for (LEVELNODE const* i = gpWorldLevelData[grid_no].pRoofHead; i; i = i->pNext)
				{
					UINT32 const tile_type = GetTileType(i->usIndex);
					if (tile_type < FIRSTROOF && LASTROOF < tile_type) continue;
					// found a roof, so return its type.
					return tile_type;
				}
			}
		}
	}
	return 0xFFFF;
}