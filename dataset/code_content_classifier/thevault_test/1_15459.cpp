bool K2HShm::ContractMmapInfo(void)
{
	if(!IsAttached()){
		ERR_K2HPRN("There is no attached K2HASH.");
		return false;
	}

	// make now area information into mmapinfo list
	PK2HMMAPINFO	pAreaListTop = new K2HMMAPINFO;
	{
		// add K2H_AREA_K2H type because areas does not have it.
		pAreaListTop->type			= K2H_AREA_K2H;
		pAreaListTop->file_offset	= 0L;
		pAreaListTop->mmap_base		= NULL;
		pAreaListTop->length		= sizeof(K2H);
	}

	PK2HAREA	pK2hArea = &(pHead->areas[0]);
	for(int	nCnt = 0; nCnt < MAX_K2HAREA_COUNT && K2H_AREA_UNKNOWN != pK2hArea->type; pK2hArea++, nCnt++){
		PK2HMMAPINFO	pinfo	= new K2HMMAPINFO;
		pinfo->type				= pK2hArea->type;
		pinfo->file_offset		= pK2hArea->file_offset;
		pinfo->mmap_base		= NULL;
		pinfo->length			= pK2hArea->length;

		k2h_mmap_info_list_add(&pAreaListTop, pinfo);
	}

	// check and munmap
	bool	result = MmapInfos.Unmap(pAreaListTop);

	k2h_mmap_info_list_freeall(&pAreaListTop);

	return result;
}