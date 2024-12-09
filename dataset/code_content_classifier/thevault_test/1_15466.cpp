unsigned char* K2HLowOpsQueue::GetPlannedPopQueueKey(size_t& keylen) const
{
	if(!IsSafe()){
		ERR_K2HPRN("This object is not safe.");
		return NULL;
	}
	unsigned char*	pkey = NULL;
	if(!Read(&pkey, keylen, 0, NULL)){						// [NOTE] always get from top of queue and encpass is NULL
		ERR_K2HPRN("Failed to read top queue key name for %s.", (isFIFO ? "FIFO" : "LIFO"));
		return NULL;
	}
	return pkey;
}