void lmtable::concatenate_single_level(int level, const char* fromfilename, const char* tofilename){
		//single level files should have a name derived from "fromfilename" and "tofilename"
		char fromnameNgrams[BUFSIZ];
		char tonameNgrams[BUFSIZ];
		sprintf(fromnameNgrams,"%s-%dgrams",fromfilename,level);
		sprintf(tonameNgrams,"%s-%dgrams",tofilename,level);
		
		VERBOSE(2,"concatenating " << level << "-grams probs from " << fromnameNgrams << " to " << tonameNgrams<< std::endl);
		
		
		//concatenating of new table to the existing data
		char cmd[BUFSIZ];
		sprintf(cmd,"cat %s >> %s", fromnameNgrams, tonameNgrams);
		system(cmd);
	}