void PeptideNamespace::Peptide::removeUnlabeledFrags()
{
	for(auto it = fragments.begin(); it != fragments.end();)
	{
		if(!it->getFound())
			fragments.erase(it);
		else ++it;
	}
}