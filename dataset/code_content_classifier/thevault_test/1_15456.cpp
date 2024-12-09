bool k2h_trans_cntl(k2h_h handle, PTRANSOPT pOpt)
{
	if(!pOpt){
		ERR_K2HPRN("Parameters are wrong.");
		return false;
	}
	if(pOpt->isEnable && '\0' == pOpt->szFilePath[0]){
		ERR_K2HPRN("Transaction enabled flag but file path is empty.");
		return false;
	}
	// if enabled, this default transaction control function does not use param.

	return true;
}