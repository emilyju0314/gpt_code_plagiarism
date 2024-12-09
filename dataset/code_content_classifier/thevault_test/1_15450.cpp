PK2HAREA K2HShm::GetLastestArea(void) const
{
	if(!IsAttached()){
		ERR_K2HPRN("There is no attached K2HASH.");
		return NULL;
	}

	// mmap loop for all index area
	for(int nCnt = MAX_K2HAREA_COUNT; 0 < nCnt; nCnt--){
		if(K2H_AREA_UNKNOWN != (pHead->areas[nCnt - 1]).type){
			// check same area for PAGELIST and PAGE
			if(K2H_AREA_PAGELIST == (pHead->areas[nCnt - 1]).type || K2H_AREA_PAGE == (pHead->areas[nCnt - 1]).type){
				bool	isfound = false;
				for(int nCnt2 = nCnt - 1; 0 < nCnt2; nCnt2--){
					if((pHead->areas[nCnt - 1]).type == (pHead->areas[nCnt2 - 1]).type){
						isfound = true;
						break;
					}
				}
				if(!isfound){
					// there is not same type area before pK2HArea.
					MSG_K2HPRN("### type = %ld is first area in k2hash, so it can not be removed.", (pHead->areas[nCnt - 1]).type);
					return NULL;
				}
			}
			return &pHead->areas[nCnt - 1];
		}
	}
	return NULL;
}