PELEMENT K2HShm::ReserveElement(void* pRelExpArea, size_t ExpLength)
{
	if(!pRelExpArea || 0UL == ExpLength){
		ERR_K2HPRN("Parameter is wrong.");
		return NULL;
	}
	if(!IsAttached()){
		ERR_K2HPRN("There is no attached K2HASH.");
		return NULL;
	}
	K2HLock		ALObjFEC(ShmFd, Rel(&(pHead->free_element_count)), K2HLock::RWLOCK);	// LOCK

	PELEMENT	pStartPos	= reinterpret_cast<PELEMENT>(pRelExpArea);
	PELEMENT	pLastPos	= ADDPTR(reinterpret_cast<PELEMENT>(pRelExpArea), static_cast<off_t>(ExpLength));

	for(PELEMENT pElement = static_cast<PELEMENT>(Abs(pHead->pfree_elements)), pRelElement = pHead->pfree_elements; pElement; pElement = static_cast<PELEMENT>(Abs(pElement->same)), pRelElement = pElement->same){
		// check target area
		if(pRelElement < pStartPos || pLastPos <= pRelElement){
			// found element and cut off it.
			PELEMENT	pPrevElement = static_cast<PELEMENT>(Abs(pElement->parent));
			PELEMENT	pNextElement = static_cast<PELEMENT>(Abs(pElement->same));
			if(pPrevElement){
				pPrevElement->same = pElement->same;
			}else{
				pHead->pfree_elements = pElement->same;
			}
			if(pNextElement){
				pNextElement->parent = pElement->parent;
			}

			pElement->parent= NULL;
			pElement->same	= NULL;
			pElement->small	= NULL;
			pElement->big	= NULL;

			if(0 < pHead->free_element_count){
				pHead->free_element_count -= 1UL;
			}
			return pElement;
		}
	}
	// not found
	return NULL;
}