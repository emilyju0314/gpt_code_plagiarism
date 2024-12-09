void PasteTextureCommon(UINT32 const map_idx)
{
	UINT16 const paste = CurrentPaste;
	if (paste   == NO_TILE) return;
	if (map_idx >= GRIDSIZE)  return;

	// Set undo, then set new
	AddToUndoList(map_idx);

	if (paste == DEEPWATERTEXTURE)
	{ // If we are pasting deep water and we are not over water, ignore!
		LEVELNODE const* const land = FindTypeInLandLayer(map_idx, REGWATERTEXTURE);
		if (!land || !gTileDatabase[land->usIndex].ubFullTile) return;
	}

	// Don't draw over floors
	if (TypeRangeExistsInLandLayer(map_idx, FIRSTFLOOR, FOURTHFLOOR)) return;

	// Compare heights and do appropriate action
	UINT8 last_high_level;
	if (AnyHeigherLand(map_idx, paste, &last_high_level))
	{
		/* Here we do the following:
		 * - Remove old type from layer
		 * - Smooth World with old type
		 * - Add a 3 by 3 square of new type at head
		 * - Smooth World with new type */
		PasteHigherTexture(map_idx, paste);
	}
	else
	{
		PasteTextureEx(map_idx, paste);
		SmoothTerrainRadius(map_idx, paste, 1, TRUE);
	}
}