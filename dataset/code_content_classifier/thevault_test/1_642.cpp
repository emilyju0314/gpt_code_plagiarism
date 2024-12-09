int parseline(istream& inp, int Order,ngram& ng,float& prob,float& bow)
{
	
	const char* words[1+ LMTMAXLEV + 1 + 1];
	int howmany;
	char line[MAX_LINE];
	
	inp.getline(line,MAX_LINE);
	if (strlen(line)==MAX_LINE-1) {
		std::stringstream ss_msg;
		ss_msg << "parseline: input line exceed MAXLINE (" << MAX_LINE << ") chars " << line << "\n";
		
		exit_error(IRSTLM_ERROR_DATA, ss_msg.str());
	}
	
	howmany = parseWords(line, words, Order + 3);
	
	if (!(howmany == (Order+ 1) || howmany == (Order + 2))){
		MY_ASSERT(howmany == (Order+ 1) || howmany == (Order + 2));
	}
	
	//read words
	ng.size=0;
	for (int i=1; i<=Order; i++)
		ng.pushw(strcmp(words[i],"<unk>")?words[i]:ng.dict->OOV());
	
	//read logprob/code and logbow/code
	MY_ASSERT(sscanf(words[0],"%f",&prob));
	if (howmany==(Order+2)){
		MY_ASSERT(sscanf(words[Order+1],"%f",&bow));
	}else{
		bow=0.0; //this is log10prob=0 for implicit backoff
	}
	return 1;
}