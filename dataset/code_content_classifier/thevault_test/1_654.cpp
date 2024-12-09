void lmtable::dumplm(fstream& out,ngram ng, int ilev, int elev, table_entry_pos_t ipos,table_entry_pos_t epos)
	{
		
		LMT_TYPE ndt=tbltype[ilev];
		ngram ing(ng.dict);
		int ndsz=nodesize(ndt);
		
		MY_ASSERT(ng.size==ilev-1);
		
		//Note that ipos and epos are always larger than or equal to 0 because they are unsigned int
		MY_ASSERT(epos<=cursize[ilev]);
		MY_ASSERT(ipos<epos);
		ng.pushc(0);
		
		for (table_entry_pos_t i=ipos; i<epos; i++) {
			char* found=table[ilev]+ (table_pos_t) i * ndsz;
			*ng.wordp(1)=word(found);
			
			float ipr=prob(found,ndt);
			
			//skip pruned n-grams
			if(isPruned && ipr==NOPROB) continue;
			
			if (ilev<elev) {
				//get first and last successor position
				table_entry_pos_t isucc=(i>0?bound(table[ilev]+ (table_pos_t) (i-1) * ndsz,ndt):0);
				table_entry_pos_t esucc=bound(found,ndt);
				
				if (isucc < esucc) //there are successors!
					dumplm(out,ng,ilev+1,elev,isucc,esucc);
			} else {
				out << ipr <<"\t";
				
				// if table is inverted then revert n-gram
				if (isInverted && (ng.size>1)) {
					ing.invert(ng);
					for (int k=ing.size; k>=1; k--) {
						if (k<ing.size) out << " ";
						out << lmtable::getDict()->decode(*ing.wordp(k));
					}
				} else {
					for (int k=ng.size; k>=1; k--) {
						if (k<ng.size) out << " ";
						out << lmtable::getDict()->decode(*ng.wordp(k));
					}
				}
				
				if (ilev<maxlev) {
					float ibo=bow(table[ilev]+ (table_pos_t)i * ndsz,ndt);
					if (isQtable){
						out << "\t" << ibo;
					}
					else{
						if ((ibo>UPPER_SINGLE_PRECISION_OF_0 || ibo<-UPPER_SINGLE_PRECISION_OF_0)) out << "\t" << ibo;
					}
				}
				out << "\n";
			}
		}
	}