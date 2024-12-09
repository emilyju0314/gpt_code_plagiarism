void lmtable::loadbin_dict(istream& inp)
	{
		VERBOSE(2,"lmtable::loadbin_dict()" << std::endl);
		lmtable::getDict()->load(inp);		
		VERBOSE(2,"dict->size(): " << lmtable::getDict()->size() << std::endl);
	}