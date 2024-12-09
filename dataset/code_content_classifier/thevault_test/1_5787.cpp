size_t PeptideNamespace::Peptide::nModsInSpan(size_t beg, size_t end) const
{
	size_t ret = 0;
	for(auto it = modLocs.begin(); it != modLocs.end(); ++it)
		if(utils::inSpan(beg, end, *it))
			ret++;
	return ret;
}