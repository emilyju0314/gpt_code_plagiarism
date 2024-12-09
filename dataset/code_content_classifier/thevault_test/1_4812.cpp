const BencEntity *BencodedDict::Get(const char* key, int len) const
{
	assert(bencType == BENC_DICT);
	assert(dict);
	BencKey Key( (unsigned char *) key, len < 0 ? (int)strlen(key) : len);
	BencodedEntityMap::const_iterator it = dict->find( Key );
	if( it == dict->end() )
		return NULL;
	else
		return &(it->second);
}