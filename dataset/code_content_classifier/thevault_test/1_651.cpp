void lmtable::loadbin_header(istream& inp,const char* header)
	{
		
		// read rest of header
		inp >> maxlev;
		
		//set the inverted falg to false, in order to rely on the header only
		isInverted=false;
		
		if (strncmp(header,"Qblmt",5)==0) {
			isQtable=true;
			if (strncmp(header,"QblmtI",6)==0)
				isInverted=true;
		} else if(strncmp(header,"blmt",4)==0) {
			isQtable=false;
			if (strncmp(header,"blmtI",5)==0)
				isInverted=true;
		} else error((char*)"loadbin: LM file is not in binary format");
		
		configure(maxlev,isQtable);
		
		for (int l=1; l<=maxlev; l++) {
			inp >> cursize[l];
			maxsize[l]=cursize[l];
		}
		
		char header2[MAX_LINE];
		if (isQtable) {
			inp >> header2;
			for (int i=1; i<=maxlev; i++) {
				inp >> NumCenters[i];
				VERBOSE(2,"reading  " << NumCenters[i] << " centers" << "\n");
			}
		}
		inp.getline(header2, MAX_LINE);
	}