void RebuildRoof(UINT32 const map_idx, UINT16 roof_type)
{
	if (roof_type ==      0) roof_type = SearchForRoofType(map_idx);
	if (roof_type == 0xFFFF) return; // No roof type around, so don't draw one.

	AddToUndoList(map_idx);
	EraseRoof(map_idx);

	//Analyse the mapindex for walls and set the flags.
	//NOTE:  There is no support for more than 2 side on a roof, so if there is, draw TOPLEFT
	bool   const top      = GetHorizontalWall(map_idx - WORLD_COLS);
	bool   const left     = GetVerticalWall(  map_idx - 1);
	bool   const bottom   = GetHorizontalWall(map_idx);
	bool   const right    = GetVerticalWall(  map_idx);
	UINT16 const roof_idx =
		top     && left  ? TOPLEFT_ROOF_INDEX     :
		top     && right ? TOPRIGHT_ROOF_INDEX    :
		bottom  && left  ? BOTTOMLEFT_ROOF_INDEX  :
		bottom  && right ? BOTTOMRIGHT_ROOF_INDEX :
		top              ? TOP_ROOF_INDEX         :
		bottom           ? BOTTOM_ROOF_INDEX      :
		left             ? LEFT_ROOF_INDEX        :
		right            ? RIGHT_ROOF_INDEX       :
		CENTER_ROOF_BASE_INDEX + Random(CENTER_ROOF_VARIANTS);
	UINT16 const tile_idx = GetTileIndexFromTypeSubIndex(roof_type, roof_idx);
	AddRoofToHead(map_idx, tile_idx);
	// If the editor view roofs is off, then the new roofs need to be hidden.
	if (!fBuildingShowRoofs) HideStructOfGivenType(map_idx, roof_type, TRUE);
}