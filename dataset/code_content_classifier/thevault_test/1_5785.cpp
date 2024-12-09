std::string PeptideNamespace::FragmentIon::getLabel(bool includeMod, std::string chargeSep) const
{
	std::string str = std::string(1, _b_y);
	str += isM() ? "" : std::to_string(_num); //add ion number if not M ion
	str += includeMod ? _mod : ""; //add modification
	
	if(charge > 1)
		str += chargeSep + makeChargeLable();
	if(isNL())
		str += getNLStr();
	return str;
}