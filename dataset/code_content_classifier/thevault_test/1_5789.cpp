void PeptideNamespace::Peptide::addNeutralLoss(double lossMass, bool labelDecoyNL)
{
	//calculate neutral loss combinations
	std::vector<double> neutralLossIons;
	for(int i = 1; i <= nMod; i++)
		neutralLossIons.push_back(i * lossMass);
	
	size_t len = fragments.size();
	size_t nLosses = neutralLossIons.size();
	for(size_t i = 0; i < len; i++)
	{
		for(size_t j = 0; j < nLosses; j++)
		{
			fragments.push_back(fragments[i].makeNLFrag(neutralLossIons[j], j + 1));
			
			//calc forceLabel
			if(!labelDecoyNL){
				size_t modCount_temp = nModsInSpan(fragments.back().getBegin(), fragments.back().getEnd());
				bool forceLabel = (modCount_temp == fragments.back().getNumNl());
				fragments.back().setForceLabel(forceLabel);
			}//end if
		}//end for j
	}//end for i
}