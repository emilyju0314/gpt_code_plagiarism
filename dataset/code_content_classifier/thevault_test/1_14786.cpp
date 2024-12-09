static BOOLEAN ShopkeeperAutoPlaceObject(SOLDIERTYPE* pSoldier, OBJECTTYPE* pObject, BOOLEAN fNewItem)
{
	OBJECTTYPE CopyOfObject;
	UINT8 ubObjectsLeftToPlace;

	// the entire pObj will get memset to 0 by RemoveObjs() if all the items are successfully placed,
	// so we have to keep a copy to retrieve with every iteration of the loop
	CopyOfObject = *pObject;


	ubObjectsLeftToPlace = pObject->ubNumberOfObjects;

	while ( ubObjectsLeftToPlace > 0 )
	{
		// figure out how many to place during this loop iteration.  Can't do more than MAX_OBJECTS_PER_SLOT at a time
		pObject->ubNumberOfObjects = MIN( MAX_OBJECTS_PER_SLOT, ubObjectsLeftToPlace);
		ubObjectsLeftToPlace -= pObject->ubNumberOfObjects;

		if (!AutoPlaceObject( pSoldier, pObject, fNewItem ))
		{
			// no more room, didn't all fit - add back in any that we didn't even get to yet
			pObject->ubNumberOfObjects += ubObjectsLeftToPlace;
			return( FALSE );
		}

		// restore object properties from our backup copy
		*pObject = CopyOfObject;
	}

	return( TRUE );
}