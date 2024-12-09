int lmtable::addwithoffset(ngram& ng, float iprob, float ibow)
	{
		char *found;
		LMT_TYPE ndt=tbltype[1]; //default initialization
		int ndsz=nodesize(ndt); //default initialization
		static int no_more_msg = 0;
		
		if (ng.size>1) {
			
			// find the prefix starting from the first level
			table_entry_pos_t start=0;
			table_entry_pos_t end=cursize[1];		
			table_entry_pos_t position;
			
			for (int l=1; l<ng.size; l++) {
				
				ndt=tbltype[l];
				ndsz=nodesize(ndt);
				
				if (search(l,start,(end-start),ndsz, ng.wordp(ng.size-l+1),LMT_FIND, &found)) {
					
					//update start and end positions for next step
					if (l < (ng.size-1)) {
						//set start position
						if (found==table[l]){
							start=0; //first pos in table
						}
						else {
							position=(table_entry_pos_t) (((table_pos_t) (found)-(table_pos_t) table[l])/ndsz);
							start=startpos[l][position];
						}
						
						end=boundwithoffset(found,ndt,l);
					}
				} else {
					if (!no_more_msg)
					{
						VERBOSE(2, "warning: missing back-off (at level " << l << ") for ngram " << ng << " (and possibly for others)" << std::endl);
					}
					no_more_msg++;
					if (!(no_more_msg % 5000000))
					{
						VERBOSE(2, "!" << std::endl);
					}
					return 0;
				}
			}
			
			// update book keeping information about level ng-size -1.
			position=(table_entry_pos_t) (((table_pos_t) found-(table_pos_t) table[ng.size-1])/ndsz);
			
			// if this is the first successor update start position in the previous level
			if (startpos[ng.size-1][position]==BOUND_EMPTY1)
				startpos[ng.size-1][position]=cursize[ng.size];
			
			//always update ending position
			boundwithoffset(found,ndt,cursize[ng.size]+1,ng.size-1);
		}
		
		// just add at the end of table[ng.size]
		
		MY_ASSERT(cursize[ng.size]< maxsize[ng.size]); // is there enough space?
		ndt=tbltype[ng.size];
		ndsz=nodesize(ndt);
		
		found=table[ng.size] + ((table_pos_t) cursize[ng.size] * ndsz);
		word(found,*ng.wordp(1));
		prob(found,ndt,iprob);
		if (ng.size<maxlev) {
			//find the bound of the previous entry
			table_entry_pos_t newend;
			if (found==table[ng.size])			newend=0; //first pos in table
			else 			newend=boundwithoffset(found - ndsz,ndt,ng.size);
			
			bow(found,ndt,ibow);
			boundwithoffset(found,ndt,newend,ng.size);
		}
		cursize[ng.size]++;
		
		if (!(cursize[ng.size]%5000000))
		{			
			VERBOSE(1, "." << std::endl);
		}
		return 1;
		
	}