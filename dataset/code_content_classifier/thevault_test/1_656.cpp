double lmtable::lprob(ngram ong,double* bow, int* bol, char** maxsuffptr,unsigned int* statesize,
												bool* extendible, double *lastbow)
	{
		VERBOSE(3," lmtable::lprob(ngram) ong " << ong  << "\n");
		
		if (ong.size==0) return 0.0; //sanity check
		if (ong.size>maxlev) ong.size=maxlev; //adjust n-gram level to table size
		
		if (bow) *bow=0; //initialize back-off weight
		if (bol) *bol=0; //initialize bock-off level
		
		
		double rbow=0,lpr=0; //output back-off weight and logprob
		float ibow,iprob;    //internal back-off weight and logprob
		
		
		if (isInverted) {
			ngram ing=ong; //Inverted ngram TRIE
			
			ing.invert(ong);
			get(ing,ing.size,ing.size); // dig in the trie
			if (ing.lev >0) { //found something?
				iprob=ing.prob;
				lpr = (double)(isQtable?Pcenters[ing.lev][(qfloat_t)iprob]:iprob);
				if (*ong.wordp(1)==dict->oovcode()) lpr-=logOOVpenalty; //add OOV penalty
				if (statesize)  *statesize=MIN(ing.lev,(ing.size-1)); //find largest n-1 gram suffix
				if (maxsuffptr) *maxsuffptr=ing.path[MIN(ing.lev,(ing.size-1))];
				if (extendible) *extendible=succrange(ing.path[ing.lev],ing.lev)>0;
				if (lastbow) *lastbow=(double) (isQtable?Bcenters[ing.lev][(qfloat_t)ing.bow]:ing.bow);
			} else { // means a real unknown word!
				lpr=-log(UNIGRAM_RESOLUTION)/M_LN10;
				if (statesize)  *statesize=0;     //default statesize for zero-gram!
				if (maxsuffptr) *maxsuffptr=NULL; //default stateptr for zero-gram!
			}
			
			if (ing.lev < ing.size) { //compute backoff weight
				int depth=(ing.lev>0?ing.lev:1); //ing.lev=0 (real unknown word) is still a 1-gram
				if (bol) *bol=ing.size-depth;
				ing.size--; //get n-gram context
				get(ing,ing.size,ing.size); // dig in the trie
				if (ing.lev>0) { //found something?
					//collect back-off weights
					for (int l=depth; l<=ing.lev; l++) {
						//start from first back-off level
						MY_ASSERT(ing.path[l]!=NULL); //check consistency of table
						ibow=this->bow(ing.path[l],tbltype[l]);
						rbow+= (double) (isQtable?Bcenters[l][(qfloat_t)ibow]:ibow);
						//avoids bad quantization of bow of <unk>
						//    if (isQtable && (*ing.wordp(1)==dict->oovcode())) {
						if (isQtable && (*ing.wordp(ing.size)==dict->oovcode())) {
							rbow-=(double)Bcenters[l][(qfloat_t)ibow];
						}
					}
				}
			}
			
			if (bow) (*bow)=rbow;
			return rbow + lpr;
		} //Direct ngram TRIE
		else {
			MY_ASSERT((extendible == NULL) || (extendible && *extendible==false));
			//		MY_ASSERT(lastbow==NULL);
			for (ngram ng=ong; ng.size>0; ng.size--) {
				if (get(ng,ng.size,ng.size)) {
					iprob=ng.prob;
					lpr = (double)(isQtable?Pcenters[ng.size][(qfloat_t)iprob]:iprob);
					if (*ng.wordp(1)==dict->oovcode()) lpr-=logOOVpenalty; //add OOV penalty
					if (maxsuffptr || statesize) { //one extra step is needed if ng.size=ong.size
						if (ong.size==ng.size) {
							ng.size--;
							get(ng,ng.size,ng.size);
						}
						if (statesize)  *statesize=ng.size;
						if (maxsuffptr) *maxsuffptr=ng.link; //we should check ng.link != NULL
					}
					return rbow+lpr;
				} else {
					if (ng.size==1) { //means a real unknow word!
						if (maxsuffptr) *maxsuffptr=NULL; //default stateptr for zero-gram!
						if (statesize)  *statesize=0;
						return rbow -log(UNIGRAM_RESOLUTION)/M_LN10;
					} else { //compute backoff
						if (bol) (*bol)++; //increase backoff level
						if (ng.lev==(ng.size-1)) { //if search stopped at previous level
							ibow=ng.bow;
							rbow+= (double) (isQtable?Bcenters[ng.lev][(qfloat_t)ibow]:ibow);
							//avoids bad quantization of bow of <unk>
							if (isQtable && (*ng.wordp(2)==dict->oovcode())) {
								rbow-=(double)Bcenters[ng.lev][(qfloat_t)ibow];
							}
						}
						if (bow) (*bow)=rbow;
					}
					
				}
				
			}
		}
		MY_ASSERT(0); //never pass here!!!
		return 1.0;
	}