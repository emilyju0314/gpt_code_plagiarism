void lmtable::checkbounds(int level)
	{
		VERBOSE(2,"lmtable::checkbounds START Level:" << level << endl);
		
		if (getCurrentSize(level) > 0 ){
			
			char*  tbl=table[level];
			char*  succtbl=table[level+1];
			
			LMT_TYPE ndt=tbltype[level];
			LMT_TYPE succndt=tbltype[level+1];
			int ndsz=nodesize(ndt);
			int succndsz=nodesize(succndt);
			
			//re-order table at level+1 on disk
			//generate random filename to avoid collisions
			
			std::string filePath;
			//  ofstream out;
			mfstream out;
			createtempfile(out, filePath, ios::out|ios::binary);
			
			if (out.fail())
			{
				perror("checkbound creating out on filePath");
				exit(4);
			}
			
			table_entry_pos_t start,end,newend;
			table_entry_pos_t succ;
			
			//re-order table at level l+1
			char* found;
			for (table_entry_pos_t c=0; c<cursize[level]; c++) {
				found=tbl+(table_pos_t) c*ndsz;
				start=startpos[level][c];
				end=boundwithoffset(found,ndt,level);
				
				if (c>0) newend=boundwithoffset(found-ndsz,ndt,level);
				else 		newend=0;
				
				//if start==BOUND_EMPTY1 there are no successors for this entry
				if (start==BOUND_EMPTY1){
					succ=0;
				}
				else{
					MY_ASSERT(end>start);
					succ=end-start;
				}
				
				startpos[level][c]=newend;
				newend += succ;
				
				MY_ASSERT(newend<=cursize[level+1]);
				
				if (succ>0) {
					out.write((char*)(succtbl + (table_pos_t) start * succndsz),(table_pos_t) succ * succndsz);
					if (!out.good()) {
						VERBOSE(2," Something went wrong while writing temporary file " << filePath << " Maybe there is not enough space on this filesystem" << endl);
						
						out.close();
						exit(2);
						removefile(filePath);
					}
				}
				
				boundwithoffset(found,ndt,newend,level);
			}
			out.close();	
			if (out.fail())
			{
				perror("error closing out");
				exit(4);
			}
			
			fstream inp(filePath.c_str(),ios::in|ios::binary);
			if (inp.fail())
			{
				perror("error opening inp");
				exit(4);
			}
			
			inp.read(succtbl,(table_pos_t) cursize[level+1]*succndsz);
			inp.close();
			if (inp.fail())
			{
				perror("error closing inp");
				exit(4);
			}
			
			removefile(filePath);
		}
		VERBOSE(2,"lmtable::checkbounds END Level:" << level << endl);
	}