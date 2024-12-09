std::string PeptideNamespace::concatMods(PeptideNamespace::PepIonIt begin, PeptideNamespace::PepIonIt end)
{
	std::string ret;
	for(auto it = begin; it != end; ++it)
		if(it->hasDynamicMod())
			ret += it->getMod();
	return ret;
}