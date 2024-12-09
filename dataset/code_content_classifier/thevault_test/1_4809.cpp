void BencEntityMem::SetStr(const char* ss, int len /*= -1*/)
{
	assert(bencType == BENC_STR);
	assert(mem);
	if(len == -1 && ss){
		len = (int)strlen(ss);
		assert(len >= 0);
	}
	mem->Clear();
	if( len && ss ){
		mem->AppendTerminated( (const unsigned char *) ss, len );
	}
}