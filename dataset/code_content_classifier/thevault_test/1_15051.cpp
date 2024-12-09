void PlaceRoadMacroAtGridNo( INT32 iMapIndex, INT32 iMacroID )
{
	INT32 i;
	i = gsRoadMacroStartIndex[ iMacroID ];
	while( gRoadMacros[ i ].sMacroID == iMacroID )
	{
		AddToUndoList( iMapIndex + gRoadMacros[ i ].sOffset );
		RemoveAllObjectsOfTypeRange( i, ROADPIECES, ROADPIECES );
		UINT16 usTileIndex = GetTileIndexFromTypeSubIndex(ROADPIECES, i + 1);
		AddObjectToHead( iMapIndex + gRoadMacros[ i ].sOffset, usTileIndex );
		i++;
	}
}