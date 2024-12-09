int lmtable::reload(std::set<string> words)
	{
		//build dictionary
		dictionary dict(NULL,(int)words.size());
		dict.incflag(1);
		
		std::set<string>::iterator w;
		for (w = words.begin(); w != words.end(); ++w)
			dict.encode((*w).c_str());
		
		return 1;
	}