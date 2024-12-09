std::string PeptideNamespace::FragmentIon::getFormatedLabel() const
{
	std::string str = std::string(1, _b_y) + (isM() ? "" : "[" + std::to_string(_num) + "]");
	
	if(!_mod.empty())
		str += " *\"" + _mod + "\"";
	
	if(charge > 1)
		str += "^\"" + makeChargeLable() + "\"";
	
	if(isNL())
		str += getNLStr();
	
	return str;
}