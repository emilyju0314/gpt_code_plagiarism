double lmtable::clprob(ngram ong,double* bow, int* bol, char** state,unsigned int* statesize,bool* extendible)
	{
		VERBOSE(3,"double lmtable::clprob(ngram ong,double* bow, int* bol, char** state,unsigned int* statesize,bool* extendible) ong:|" << ong  << "|\n");
		
#ifdef TRACE_CACHELM
		//		if (probcache && ong.size==maxlev && sentence_id>0) {
		if (probcache && sentence_id>0) {
			*cacheout << sentence_id << " " << ong << "\n";
		}
#endif
		
		if (ong.size==0) {
			if (statesize!=NULL) *statesize=0;
			if (state!=NULL) *state=NULL;
			if (extendible!=NULL) *extendible=false;
			return 0.0;
		}
		
		if (ong.size>maxlev) ong.size=maxlev; //adjust n-gram level to table size
		
#ifdef PS_CACHE_ENABLE
		double logpr = 0.0;
		//cache hit
		prob_and_state_t pst_get;
		
		//		if (prob_and_state_cache && ong.size==maxlev && prob_and_state_cache->get(ong.wordp(maxlev),pst_get)) {
		if (prob_and_state_cache[ong.size] && prob_and_state_cache[ong.size]->get(ong.wordp(ong.size),pst_get)) {
			logpr=pst_get.logpr;
			if (bow) *bow = pst_get.bow;
			if (bol) *bol = pst_get.bol;
			if (state) *state = pst_get.state;
			if (statesize) *statesize = pst_get.statesize;
			if (extendible) *extendible = pst_get.extendible;
			
			return logpr;
		}
		
		//cache miss
		
		prob_and_state_t pst_add;
		logpr = pst_add.logpr = lmtable::lprob(ong, &(pst_add.bow), &(pst_add.bol), &(pst_add.state), &(pst_add.statesize), &(pst_add.extendible));
		
		
		if (bow) *bow = pst_add.bow;
		if (bol) *bol = pst_add.bol;
		if (state) *state = pst_add.state;
		if (statesize) *statesize = pst_add.statesize;
		if (extendible) *extendible = pst_add.extendible;
		
		
		//		if (prob_and_state_cache && ong.size==maxlev) {
		//			prob_and_state_cache->add(ong.wordp(maxlev),pst_add);
		//    }
		if (prob_and_state_cache[ong.size]) {
			prob_and_state_cache[ong.size]->add(ong.wordp(ong.size),pst_add);
		}
		return logpr;
#else
		return lmtable::lprob(ong, bow, bol, state, statesize, extendible);
#endif
	}