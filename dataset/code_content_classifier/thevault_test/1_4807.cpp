const unsigned char* BencEntity::ParseInPlace(const unsigned char *p, BencEntity &ent, const unsigned char *pend, const char* key, std::pair<unsigned char*, unsigned char*> *rgn)
{
	assert( rgn );
	// InplaceMemRegime regime;
	AllocateMemRegime regime; // in place not supported yet
	BencParserElement parser(const_cast<unsigned char *>(p), key, pend);
	if( !BencEntity::DoParse(ent, &parser, &regime) )
		return NULL;
	parser.GetElement( &(rgn->first), &( rgn->second ) );
	return parser.GetPos();
}