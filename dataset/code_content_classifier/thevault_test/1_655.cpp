const char *lmtable::cmaxsuffptr(int* codes, int sz, unsigned int* size)
	{
		VERBOSE(3,"const char *lmtable::cmaxsuffptr(int* codes, int sz, unsigned int* size)\n");
		
		if (sz==0) {
			if (size!=NULL) *size=0;
			return (char*) NULL;
		}
		
		if (sz>maxlev) sz=maxlev; //adjust n-gram level to table size
		
#ifdef PS_CACHE_ENABLE
		//cache hit
		prob_and_state_t pst;
		
		//cache hit
		//		if (prob_and_state_cache && sz==maxlev && prob_and_state_cache->get(codes,pst)) {
		if (prob_and_state_cache[sz] && prob_and_state_cache[sz]->get(codes,pst)) {
			if (size) *size = pst.statesize;
			return pst.state;
		}
		
		//create the actual ngram
		ngram ong(dict);
		ong.pushc(codes,sz);
		MY_ASSERT (ong.size == sz);
		
		//cache miss
		unsigned int isize; //internal state size variable
		char* found=(char *)maxsuffptr(ong,&isize);
		
		//cache insert
		//IMPORTANT: this function updates only two fields (state, statesize) of the entry of the cache; the reminaing fields (logpr, bow, bol, extendible) are undefined; hence, it should not be used before the corresponding clprob()
		if (ong.size>=maxlev) ong.size=maxlev;
		//		if (prob_and_state_cache && ong.size==maxlev) {
		if (prob_and_state_cache[sz]) {
			pst.state=found;
			pst.statesize=isize;
			//			prob_and_state_cache->add(ong.wordp(maxlev),pst);
			prob_and_state_cache[sz]->add(ong.wordp(ong.size),pst);
		}
		if (size!=NULL) *size=isize;
		return found;
#else
		//create the actual ngram
		ngram ong(dict);
		ong.pushc(codes,sz);
		MY_ASSERT (ong.size == sz);
		/*
		 unsigned int isize; //internal state size variable
		 char* found=(char *) maxsuffptr(ong,&isize);
		 char* found2=(char *) maxsuffptr(ong,size);
		 if (size!=NULL) *size=isize;
		 return found;
		 */
		return maxsuffptr(ong,size);
#endif
	}