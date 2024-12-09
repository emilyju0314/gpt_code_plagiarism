void PeptideNamespace::Peptide::fixDiffMod(const aaDB::AADB& aminoAcidsMasses,
										   const char* diffmods)
{
	//check if n term mod
	double nTermMod = 0;
	if(sequence[0] == '('){
		nTermMod = parseStaticMod(0);
	}
	
	//check that n term is not a diff mod
	for(const char* p = diffmods; *p; p++)
		if(sequence[0] == *p)
			throw std::runtime_error("Invalid peptide sequence: " + sequence);
	
	//Check that first char is now a letter
	if(!isalpha(sequence[0]))
		throw std::runtime_error("Invalid peptide sequence: " + sequence);
	
	for(size_t i = 0; i < sequence.length(); i++)
	{
		//first check if current index is a modification.
		if(sequence[i] == '(')
		{
			double m = parseStaticMod(i);
			aminoAcids.back().addStaticMod(m);
		}
		for(const char* p = diffmods; *p; p++){
			if(sequence[i] == *p){
				aminoAcids.back().setDynamicMod(sequence[i],
												aminoAcidsMasses.getMW(sequence[i]));
				sequence.erase(i, 1);
				modLocs.push_back(int(aminoAcids.size() - 1)); //add location of mod to modLocs
				nMod++; //increment nMod
			}
		}
		
		//exit loop if at end of sequence
		if(i >= sequence.length())
			break;
		
		//Check that current char is letter
		if(!isalpha(sequence[i]))
			throw std::runtime_error("Invalid peptide sequence: " + sequence);
		
		//add new amino acid to
		aminoAcids.emplace_back(aminoAcidsMasses.getMW(sequence[i]));
	}//end for
	
	//add n-terminal modification
	aminoAcids.begin()->addStaticMod(nTermMod);
}