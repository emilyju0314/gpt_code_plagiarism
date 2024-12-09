void lmtable::cpsublm(lmtable* slmt, dictionary* subdict,bool keepunigr)
	{
		
		//keepunigr=false;
		//let slmt inherit all features of this lmtable
		
		slmt->configure(maxlev,isQtable);
		slmt->dict=new dictionary((keepunigr?dict:subdict),false);
		
		if (isQtable) {
			for (int i=1; i<=maxlev; i++)  {
				slmt->NumCenters[i]=NumCenters[i];
				slmt->Pcenters[i]=new float [NumCenters[i]];
				memcpy(slmt->Pcenters[i],Pcenters[i],NumCenters[i] * sizeof(float));
				
				if (i<maxlev) {
					slmt->Bcenters[i]=new float [NumCenters[i]];
					memcpy(slmt->Bcenters[i],Bcenters[i],NumCenters[i] * sizeof(float));
				}
			}
		}
		
		//manage dictionary information
		
		//generate OOV codes and build dictionary lookup table
		dict->genoovcode();
		slmt->dict->genoovcode();
		subdict->genoovcode();
		
		int* lookup=new int [dict->size()];
		
		for (int c=0; c<dict->size(); c++) {
			lookup[c]=subdict->encode(dict->decode(c));
			if (c != dict->oovcode() && lookup[c] == subdict->oovcode())
				lookup[c]=-1; // words of this->dict that are not in slmt->dict
		}
		
		//variables useful to navigate in the lmtable structure
		LMT_TYPE ndt,pndt;
		int ndsz,pndsz;
		char *entry, *newentry;
		table_entry_pos_t start, end, origin;
		
		for (int l=1; l<=maxlev; l++) {
			
			slmt->cursize[l]=0;
			slmt->table[l]=NULL;
			
			if (l==1) { //1-gram level
				
				ndt=tbltype[l];
				ndsz=nodesize(ndt);
				
				for (table_entry_pos_t p=0; p<cursize[l]; p++) {
					
					entry=table[l] + (table_pos_t) p * ndsz;
					if (lookup[word(entry)]!=-1 || keepunigr) {
						
						if ((slmt->cursize[l] % slmt->dict->size()) ==0)
							slmt->table[l]=(char *)reallocf(slmt->table[l],((table_pos_t) slmt->cursize[l] + (table_pos_t) slmt->dict->size()) * ndsz);
						
						newentry=slmt->table[l] + (table_pos_t) slmt->cursize[l] * ndsz;
						memcpy(newentry,entry,ndsz);
						if (!keepunigr) //do not change encoding if keepunigr is true
							slmt->word(newentry,lookup[word(entry)]);
						
						if (l<maxlev)
							slmt->bound(newentry,ndt,p); //store in bound the entry itself (**) !!!!
						slmt->cursize[l]++;
					}
				}
			}
			
			else { //n-grams n>1: scan lower order table
				
				pndt=tbltype[l-1];
				pndsz=nodesize(pndt);
				ndt=tbltype[l];
				ndsz=nodesize(ndt);
				
				for (table_entry_pos_t p=0; p<slmt->cursize[l-1]; p++) {
					
					//determine start and end of successors of this entry
					origin=slmt->bound(slmt->table[l-1] + (table_pos_t)p * pndsz,pndt); //position of n-1 gram in this table (**)
					if (origin == 0) start=0;                              //succ start at first pos in table[l]
					else start=bound(table[l-1] + (table_pos_t)(origin-1) * pndsz,pndt);//succ start after end of previous entry
					end=bound(table[l-1] + (table_pos_t)origin * pndsz,pndt);           //succ end where indicated
					
					if (!keepunigr || lookup[word(table[l-1] + (table_pos_t)origin * pndsz)]!=-1) {
						while (start < end) {
							
							entry=table[l] + (table_pos_t) start * ndsz;
							
							if (lookup[word(entry)]!=-1) {
								
								if ((slmt->cursize[l] % slmt->dict->size()) ==0)
									slmt->table[l]=(char *)reallocf(slmt->table[l],(table_pos_t) (slmt->cursize[l]+slmt->dict->size()) * ndsz);
								
								newentry=slmt->table[l] + (table_pos_t) slmt->cursize[l] * ndsz;
								memcpy(newentry,entry,ndsz);
								if (!keepunigr) //do not change encoding if keepunigr is true
									slmt->word(newentry,lookup[word(entry)]);
								
								if (l<maxlev)
									slmt->bound(newentry,ndt,start); //store in bound the entry itself!!!!
								slmt->cursize[l]++;
							}
							start++;
						}
					}
					
					//updated bound information of incoming entry
					slmt->bound(slmt->table[l-1] + (table_pos_t) p * pndsz, pndt,slmt->cursize[l]);
				}
			}
		}
		
		return;
	}