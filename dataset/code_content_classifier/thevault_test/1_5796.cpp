double PeptideNamespace::calcMass(PeptideNamespace::PepIonIt begin, PeptideNamespace::PepIonIt end)
{
	double ret = 0;
	for(auto it = begin; it != end; ++it)
		ret += it->getTotalMass();
	return ret;
}