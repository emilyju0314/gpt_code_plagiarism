bool K2HLowOpsQueue::ReplaceTopQueueKey(const unsigned char* preplacekey, size_t replacekeylen)
{
	if(!IsSafe()){
		ERR_K2HPRN("This object is not safe.");
		return false;
	}
	return pK2HShm->UpdateStartK2HMarker(marker, marker_len, preplacekey, replacekeylen);
}