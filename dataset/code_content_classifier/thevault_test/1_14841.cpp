void QuickEraseMapTile( UINT32 iMapIndex )
{
	if ( iMapIndex >= GRIDSIZE )
		return;
	AddToUndoList( iMapIndex );
	DeleteStuffFromMapTile( iMapIndex );
	MarkWorldDirty();
}