int64 BencEntityLazyInt::GetInt64(int64 def /*= 0*/) {
	assert(bencType == BENC_INT_LAZY);
	if(bencType != BENC_INT_LAZY) return def;
	BencodedMem *pMem = mem;
	mem = 0;
	ParseNum( reinterpret_cast<const unsigned char*>(pMem->GetRaw()));
	delete pMem;
	bencType = BENC_INT;
	return BencEntity::GetInt64( def );
}