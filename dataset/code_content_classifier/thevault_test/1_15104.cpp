static void SortSoldierInitList(void)
{
	SOLDIERINITNODE *temp, *curr;

	if( !gSoldierInitHead )
		return;

	//1st priority sort
	curr = gSoldierInitTail;
	while( curr )
	{
		if( curr->pSoldier && curr != gSoldierInitTail )
		{
			//This node has an existing soldier, so move to end of list.
			//copy node
			temp = curr;
			if( temp == gSoldierInitHead )
			{
				//If we dealing with the head, we need to move it now.
				gSoldierInitHead = gSoldierInitHead->next;
				if( gfOriginalList )
					gOriginalSoldierInitListHead = gSoldierInitHead;
				else
					gAlternateSoldierInitListHead = gSoldierInitHead;
				gSoldierInitHead->prev = NULL;
				temp->next = NULL;
			}
			curr = curr->prev;
			//detach node from list
			if( temp->prev )
				temp->prev->next = temp->next;
			if( temp->next )
				temp->next->prev = temp->prev;
			//add node to end of list
			temp->prev = gSoldierInitTail;
			temp->next = NULL;
			gSoldierInitTail->next = temp;
			gSoldierInitTail = temp;
		}
		else
		{
			curr = curr->prev;
		}
	}
	//4th -- put to start
	curr = gSoldierInitHead;
	while( curr )
	{
		if( !curr->pSoldier && !curr->pBasicPlacement->fPriorityExistance && curr->pDetailedPlacement && curr != gSoldierInitHead )
		{
			//Priority existance nodes without detailed placement info are moved to beginning of list
			//copy node
			temp = curr;
			if( temp == gSoldierInitTail )
			{
				//If we dealing with the tail, we need to move it now.
				gSoldierInitTail = gSoldierInitTail->prev;
				gSoldierInitTail->next = NULL;
				temp->prev = NULL;
			}
			curr = curr->next;
			//detach node from list
			if( temp->prev )
				temp->prev->next = temp->next;
			if( temp->next )
				temp->next->prev = temp->prev;
			//add node to beginning of list
			temp->prev = NULL;
			temp->next = gSoldierInitHead;
			gSoldierInitHead->prev = temp;
			gSoldierInitHead = temp;
			if( gfOriginalList )
				gOriginalSoldierInitListHead = gSoldierInitHead;
			else
				gAlternateSoldierInitListHead = gSoldierInitHead;
		}
		else
		{
			curr = curr->next;
		}
	}
	//3rd priority sort (see below for reason why we do 2nd after 3rd)
	curr = gSoldierInitHead;
	while( curr )
	{
		if( !curr->pSoldier && curr->pBasicPlacement->fPriorityExistance && !curr->pDetailedPlacement && curr != gSoldierInitHead )
		{
			//Priority existance nodes without detailed placement info are moved
			//to beginning of list copy node
			temp = curr;
			if( temp == gSoldierInitTail )
			{
				//If we dealing with the tail, we need to move it now.
				gSoldierInitTail = gSoldierInitTail->prev;
				gSoldierInitTail->next = NULL;
				temp->prev = NULL;
			}
			curr = curr->next;
			//detach node from list
			if( temp->prev )
				temp->prev->next = temp->next;
			if( temp->next )
				temp->next->prev = temp->prev;
			//add node to beginning of list
			temp->prev = NULL;
			temp->next = gSoldierInitHead;
			gSoldierInitHead->prev = temp;
			gSoldierInitHead = temp;
			if( gfOriginalList )
				gOriginalSoldierInitListHead = gSoldierInitHead;
			else
				gAlternateSoldierInitListHead = gSoldierInitHead;
		}
		else
		{
			curr = curr->next;
		}
	}
	//2nd priority sort (by adding these to the front, it'll be before the
	//3rd priority sort.  This is why we do it after.
	curr = gSoldierInitHead;
	while( curr )
	{
		if( !curr->pSoldier && curr->pBasicPlacement->fPriorityExistance && curr->pDetailedPlacement && curr != gSoldierInitHead )
		{	//Priority existance nodes are moved to beginning of list
			//copy node
			temp = curr;
			if( temp == gSoldierInitTail )
			{
				//If we dealing with the tail, we need to move it now.
				gSoldierInitTail = gSoldierInitTail->prev;
				gSoldierInitTail->next = NULL;
				temp->prev = NULL;
			}
			curr = curr->next;
			//detach node from list
			if( temp->prev )
				temp->prev->next = temp->next;
			if( temp->next )
				temp->next->prev = temp->prev;
			//add node to beginning of list
			temp->prev = NULL;
			temp->next = gSoldierInitHead;
			gSoldierInitHead->prev = temp;
			gSoldierInitHead = temp;
			if( gfOriginalList )
				gOriginalSoldierInitListHead = gSoldierInitHead;
			else
				gAlternateSoldierInitListHead = gSoldierInitHead;
		}
		else
		{
			curr = curr->next;
		}
	}
	//4th priority sort
	//Done!  If the soldier existing slots are at the end of the list and the
	//       priority placements are at the beginning of the list, then the
	//       basic placements are in the middle.
}