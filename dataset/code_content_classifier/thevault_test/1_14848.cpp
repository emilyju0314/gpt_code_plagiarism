static void PasteStructureCommon(const UINT32 iMapIndex)
{
	if (iMapIndex >= GRIDSIZE) return;

	const INT32 iRandSelIndex = GetRandomSelection();
	if (iRandSelIndex == -1) return;

	AddToUndoList(iMapIndex);

	const UINT16 usUseIndex    = pSelList[iRandSelIndex].usIndex;
	const UINT16 usUseObjIndex = pSelList[iRandSelIndex].uiObject;

	// Check with Structure Database (aka ODB) if we can put the object here!
	const DB_STRUCTURE_REF* const sr = gTileDatabase[gTileTypeStartIndex[usUseObjIndex] + usUseIndex].pDBStructureRef;
	if (!OkayToAddStructureToWorld(iMapIndex, 0, sr, INVALID_STRUCTURE_ID) && sr != NULL) return;

	// Actual structure info is added by the functions below
	AddStructToHead(iMapIndex, gTileTypeStartIndex[usUseObjIndex] + usUseIndex);
}