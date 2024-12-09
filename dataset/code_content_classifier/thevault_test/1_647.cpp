void lmtable::savetxt(const char *filename)
	{
		
		fstream out(filename,ios::out);
		table_entry_pos_t cnt[1+MAX_NGRAM];
		int l;
		
		//	out.precision(7);
		out.precision(6);
		
		if (isQtable) {
			out << "qARPA " << maxlev;
			for (l=1; l<=maxlev; l++)
				out << " " << NumCenters[l];
			out << endl;
		}
		
		ngram ng(lmtable::getDict(),0);
		
		VERBOSE(2, "savetxt: " << filename << std::endl);
		
		if (isPruned) ngcnt(cnt); //check size of table by considering pruned n-grams
		
		out << "\n\\data\\\n";
		char buff[100];
		for (l=1; l<=maxlev; l++) {
			sprintf(buff,"ngram %2d=%10d\n",l,(isPruned?cnt[l]:cursize[l]));
			out << buff;
		}
		out << "\n";
		
		for (l=1; l<=maxlev; l++) {
			
			out << "\n\\" << l << "-grams:\n";
			VERBOSE(2, "save: " << (isPruned?cnt[l]:cursize[l]) << " " << l << "-grams" << std::endl);
			if (isQtable) {
				out << NumCenters[l] << "\n";
				for (int c=0; c<NumCenters[l]; c++) {
					out << Pcenters[l][c];
					if (l<maxlev) out << " " << Bcenters[l][c];
					out << "\n";
				}
			}
			
			ng.size=0;
			dumplm(out,ng,1,l,0,cursize[1]);
			
		}
		
		out << "\\end\\\n";
		VERBOSE(2, "done" << std::endl);
	}