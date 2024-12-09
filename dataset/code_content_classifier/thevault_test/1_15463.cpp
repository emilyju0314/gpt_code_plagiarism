bool K2HLowOpsQueue::Push(const unsigned char* bydata, size_t datalen, K2HAttrs* pAttrs, const char* encpass, const time_t* expire)
{
	if(!bydata || 0 == datalen || pAttrs || encpass || expire){		// [NOTE] do not use pAttrs, encpass and expire.
		ERR_K2HPRN("Parameters are wrong.");
		return false;
	}
	if(!IsSafe()){
		ERR_K2HPRN("This object is not safe.");
		return false;
	}
	return pK2HShm->AddQueue(marker, marker_len, bydata, datalen, isFIFO);
}