bool K2HLowOpsQueue::Read(unsigned char** ppdata, size_t& datalen, int pos, const char* encpass) const
{
	if(!ppdata || (0 != pos && -1 != pos) || encpass){				// [NOTE] do not use encpass and pos must be 0 or -1
		ERR_K2HPRN("Parameters are wrong.");
		return false;
	}
	if(!IsSafe()){
		ERR_K2HPRN("This object is not safe.");
		return false;
	}
	return pK2HShm->ReadQueue(marker, marker_len, ppdata, datalen, pos);
}