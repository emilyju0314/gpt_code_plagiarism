bool K2HQueue::Pop(unsigned char** ppdata, size_t& datalen, K2HAttrs** ppAttrs, const char* encpass)
{
	if(!ppdata){
		ERR_K2HPRN("Parameter is wrong.");
		return false;
	}
	if(!IsSafe()){
		ERR_K2HPRN("This object is not safe.");
		return false;
	}

	unsigned char*	pKey	= NULL;
	size_t			keylen	= 0;
	*ppdata					= NULL;
	datalen					= 0;
	if(!pK2HShm->PopQueue(marker, marker_len, &pKey, keylen, ppdata, datalen, ppAttrs, encpass)){
		ERR_K2HPRN("Something error occurred during popping.");
		K2H_Free(pKey);
		K2H_Free(*ppdata);
		return false;
	}
	K2H_Free(pKey);

	return true;
}