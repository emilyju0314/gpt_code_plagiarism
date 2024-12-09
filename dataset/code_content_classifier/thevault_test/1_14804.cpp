void AddLightToUndoList(INT32 const iMapIndex, INT32 const iLightRadius)
{
	if (!gfUndoEnabled) return;

	/* When executing an undo command (by adding a light or removing one), that
	 * command actually tries to add it to the undo list.  So we wrap the
	 * execution of the undo command by temporarily setting this flag, so it'll
	 * ignore, and not place a new undo command.  When finished, the flag is
	 * cleared, and lights are again allowed to be saved in the undo list. */
	if (gfIgnoreUndoCmdsForLights) return;

	SGP::PODObj<undo_struct> undo_info;
	undo_info->fLightSaved = TRUE;
	/* if ubLightRadius is 0, then we don't need to save the light information
	 * because we will erase it when it comes time to execute the undo command. */
	undo_info->ubLightRadius = iLightRadius;
	undo_info->iMapIndex     = iMapIndex;
	undo_info->pMapTile      = NULL;

	//Add to undo stack
	SGP::PODObj<undo_stack> n;
	n->iCmdCount    = 1;
	n->pData        = undo_info.Release();
	n->pNext        = gpTileUndoStack;
	gpTileUndoStack = n.Release();

	CropStackToMaxLength(MAX_UNDO_COMMAND_LENGTH);
}