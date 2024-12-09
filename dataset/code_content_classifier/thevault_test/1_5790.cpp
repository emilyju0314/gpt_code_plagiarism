double PeptideNamespace::Peptide::parseStaticMod(size_t startIndex)
{
	//get index of parentheses close
	size_t end = sequence.find(')', startIndex);
	if(end == std::string::npos)
		throw std::runtime_error("Invalid peptide sequence: " + sequence);
	
	//get mass of modification
	double ret = std::stod(sequence.substr(startIndex + 1, end - 1));
	//erase modification from sequence
	sequence.erase(sequence.begin() + startIndex, sequence.begin() + end + 1);
	
	return ret;
}