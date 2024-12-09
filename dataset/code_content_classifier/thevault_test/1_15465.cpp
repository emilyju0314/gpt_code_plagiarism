unsigned char* K2HLowOpsQueue::GetEdgeQueueKey(size_t& keylen, bool is_top) const
{
	if(!IsSafe()){
		ERR_K2HPRN("This object is not safe.");
		return NULL;
	}
	unsigned char*	pkey = NULL;
	if(!Read(&pkey, keylen, (is_top ? 0 : -1), NULL)){		// [NOTE] -1 means lastest position, always encpass is NULL
		ERR_K2HPRN("Failed to read %s queue key name for %s.", (is_top ? "Top" : "Bottom"), (isFIFO ? "FIFO" : "LIFO"));
		return NULL;
	}
	return pkey;
}