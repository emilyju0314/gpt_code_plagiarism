void EraseMapTile( UINT32 iMapIndex )
{
	INT32			iEraseMode;
	if ( iMapIndex >= GRIDSIZE )
		return;

	// Figure out what it is we are trying to erase
	iEraseMode = iDrawMode - DRAW_MODE_ERASE;

	switch ( iEraseMode )
	{
		case DRAW_MODE_NORTHPOINT:
		case DRAW_MODE_WESTPOINT:
		case DRAW_MODE_EASTPOINT:
		case DRAW_MODE_SOUTHPOINT:
		case DRAW_MODE_CENTERPOINT:
		case DRAW_MODE_ISOLATEDPOINT:
			SpecifyEntryPoint( iMapIndex );
			break;
		case DRAW_MODE_EXITGRID:
			AddToUndoList( iMapIndex );
			RemoveExitGridFromWorld( iMapIndex );
			RemoveTopmost( (UINT16)iMapIndex, FIRSTPOINTERS8 );
			break;
		case DRAW_MODE_GROUND:
		{
			// Is there ground on this tile? if not, get out o here
			if ( gpWorldLevelData[ iMapIndex ].pLandHead == NULL )
				break;

			// is there only 1 ground tile here? if so, get out o here
			if ( gpWorldLevelData[ iMapIndex ].pLandHead->pNext == NULL )
				break;
			AddToUndoList( iMapIndex );
			const UINT32 uiCheckType = GetTileType(gpWorldLevelData[iMapIndex].pLandHead->usIndex);
			RemoveLand( iMapIndex, gpWorldLevelData[ iMapIndex ].pLandHead->usIndex );
			SmoothTerrainRadius( iMapIndex, uiCheckType, 1, TRUE );
			break;
		}

		case DRAW_MODE_OSTRUCTS:
		case DRAW_MODE_OSTRUCTS1:
		case DRAW_MODE_OSTRUCTS2:
			AddToUndoList( iMapIndex );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTOSTRUCT, LASTOSTRUCT );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTVEHICLE, SECONDVEHICLE );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTDEBRISSTRUCT, SECONDDEBRISSTRUCT );
			RemoveAllStructsOfTypeRange( iMapIndex, NINTHOSTRUCT, TENTHOSTRUCT );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTLARGEEXPDEBRIS, SECONDLARGEEXPDEBRIS );
			RemoveAllObjectsOfTypeRange( iMapIndex, DEBRIS2MISC, DEBRIS2MISC );
			RemoveAllObjectsOfTypeRange( iMapIndex, ANOTHERDEBRIS, ANOTHERDEBRIS );
			break;
		case DRAW_MODE_DEBRIS:
			AddToUndoList( iMapIndex );
			RemoveAllObjectsOfTypeRange( iMapIndex, DEBRISROCKS, LASTDEBRIS );
			RemoveAllObjectsOfTypeRange( iMapIndex, DEBRIS2MISC, DEBRIS2MISC );
			RemoveAllObjectsOfTypeRange( iMapIndex, ANOTHERDEBRIS, ANOTHERDEBRIS );
			break;
		case DRAW_MODE_BANKS:
			AddToUndoList( iMapIndex );
			RemoveAllObjectsOfTypeRange( iMapIndex, FIRSTROAD, LASTROAD );
			// Note, for this routine, cliffs are considered a subset of banks
			RemoveAllStructsOfTypeRange( iMapIndex, ANIOSTRUCT, ANIOSTRUCT );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTCLIFF, LASTBANKS );
			RemoveAllShadowsOfTypeRange( iMapIndex, FIRSTCLIFFSHADOW, LASTCLIFFSHADOW );
			RemoveAllObjectsOfTypeRange( iMapIndex, FIRSTCLIFFHANG, LASTCLIFFHANG );
			RemoveAllStructsOfTypeRange( iMapIndex, FENCESTRUCT, FENCESTRUCT );
			RemoveAllShadowsOfTypeRange( iMapIndex, FENCESHADOW, FENCESHADOW );
			break;
		case DRAW_MODE_FLOORS:
			AddToUndoList( iMapIndex );
			RemoveAllLandsOfTypeRange( iMapIndex, FIRSTFLOOR, LASTFLOOR );
			break;
		case DRAW_MODE_ROOFS:
		case DRAW_MODE_NEWROOF:
			AddToUndoList( iMapIndex );
			RemoveAllRoofsOfTypeRange( iMapIndex, FIRSTTEXTURE, LASTITEM );
			RemoveAllOnRoofsOfTypeRange( iMapIndex, FIRSTTEXTURE, LASTITEM );
			break;
		case DRAW_MODE_WALLS:
		case DRAW_MODE_DOORS:
		case DRAW_MODE_WINDOWS:
		case DRAW_MODE_BROKEN_WALLS:
			AddToUndoList( iMapIndex );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTWALL, LASTWALL );
			RemoveAllShadowsOfTypeRange( iMapIndex, FIRSTWALL, LASTWALL );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTDOOR, LASTDOOR );
			RemoveAllShadowsOfTypeRange( iMapIndex, FIRSTDOORSHADOW, LASTDOORSHADOW );
			break;
		case DRAW_MODE_DECOR:
		case DRAW_MODE_DECALS:
		case DRAW_MODE_ROOM:
		case DRAW_MODE_TOILET:
			AddToUndoList( iMapIndex );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTWALLDECAL, LASTWALLDECAL );
			RemoveAllStructsOfTypeRange( iMapIndex, FIFTHWALLDECAL, EIGTHWALLDECAL );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTDECORATIONS, LASTDECORATIONS );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTISTRUCT, LASTISTRUCT );
			RemoveAllStructsOfTypeRange( iMapIndex, FIFTHISTRUCT, EIGHTISTRUCT );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTSWITCHES, FIRSTSWITCHES );
			break;
		case DRAW_MODE_CAVES:
			AddToUndoList( iMapIndex );
			RemoveAllStructsOfTypeRange( iMapIndex, FIRSTWALL, LASTWALL );
			break;
		case DRAW_MODE_ROOMNUM:
			PasteRoomNumber( iMapIndex, 0 );
			break;
		case DRAW_MODE_ROADS:
			RemoveAllObjectsOfTypeRange( iMapIndex, ROADPIECES, ROADPIECES );
			break;
		default:
			//DeleteStuffFromMapTile( iMapIndex );
			break;
	}
}