static void ShopkeeperAddItemToPool(INT16 const sGridNo, OBJECTTYPE* const pObject, UINT8 const ubLevel)
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

		AddItemToPool(sGridNo, pObject, VISIBLE, ubLevel, 0, 0);

		// restore object properties from our backup copy
		*pObject = CopyOfObject;
	}
}