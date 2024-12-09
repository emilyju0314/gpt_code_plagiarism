std::pair<double, double>
GetMinimumRefractiveIndex(const I3CLSimMediumProperties &med)
{
	std::pair<double, double> n_min(
	    std::numeric_limits<double>::infinity(),
	    std::numeric_limits<double>::infinity());
	
	for (unsigned j = 0; j < med.GetLayersNum(); j++) {
		if (!med.GetGroupRefractiveIndexOverride(j))
			log_fatal("Medium properties don't know how to calculate group refractive indices");
		const I3CLSimFunction &groupIndex = *(med.GetGroupRefractiveIndexOverride(j));
		const I3CLSimFunction &phaseIndex = *(med.GetPhaseRefractiveIndex(j));
		
		double wmin = std::max(med.GetMinWavelength(), groupIndex.GetMinWlen());
		double wmax = std::min(med.GetMaxWavelength(), groupIndex.GetMaxWlen());
		for (unsigned i = 0; i < 1000; i++) {
			double n = groupIndex.GetValue(wmin + i*(wmax-wmin));
			if (n > 1 && n < n_min.first) {
				n_min = std::make_pair(n, phaseIndex.GetValue(wmin + i*(wmax-wmin)));
			}
		}
	}
	
	return n_min;
}