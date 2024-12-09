bool Dtafilter::readFilterFiles(const IonFinder::Params& params,
								std::vector<Dtafilter::Scan>& scans)
{
	auto endIt = params.getFilterFiles().end();
	for(auto it = params.getFilterFiles().begin(); it != endIt; ++it)
	{
		if(!Dtafilter::readFilterFile(it->second, it->first, scans,
									  !params.getIncludeReverse(), params.getModFilter()))
			return false;
	}
	
	return true;
}