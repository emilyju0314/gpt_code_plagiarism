bool IonFinder::readInputTsv(const std::string& ifname,
							 std::vector<Dtafilter::Scan>& scans,
							 bool skipReverse, int modFilter)
{
	utils::TsvFile tsv(ifname);
	if(!tsv.read()) return false;
	
	//iterate through columns to make sure all required cols exist
	for(const auto & i : TSV_INPUT_REQUIRED_COLNAMES) {
		if(!tsv.colExists(i))
		{
			std::cerr << "\nError! Required column: " << i <<
			" not found in " << ifname << NEW_LINE;
			return false;
		}
	}
	
	//itterate through columns and search for optional columns
	std::map<std::string, bool> foundOptionalCols;
	for(int i = 0; i < TSV_INPUT_OPTIONAL_COLNAMES_LEN; i++)
	{
		if(tsv.colExists(TSV_INPUT_OPTIONAL_COLNAMES[i]))
			foundOptionalCols[TSV_INPUT_OPTIONAL_COLNAMES[i]] = true;
		else foundOptionalCols[TSV_INPUT_OPTIONAL_COLNAMES[i]] = false;
	}
	
	size_t nRow = tsv.getNrow();
	for(size_t i = 0; i < nRow; i++)
	{
		Dtafilter::Scan temp;
		temp.setMatchDirection(Dtafilter::Scan::MatchDirection::FORWARD);

		//required columns
		temp.setScanNum(tsv.getValSize(i, IonFinder::SCAN_NUM));
		temp.setSequence(tsv.getValStr(i, IonFinder::SEQUENCE));
        temp.setIsModified(temp.checkIsModified());
		temp.getPrecursor().setFile(tsv.getValStr(i, IonFinder::PRECURSOR_FILE));
		temp.setSampleName(tsv.getValStr(i, IonFinder::SAMPLE_NAME));

		//add optional columns which were found.
		if(foundOptionalCols[IonFinder::PARENT_ID])
			temp.setParentID(tsv.getValStr(i, IonFinder::PARENT_ID));
		if(foundOptionalCols[IonFinder::PARENT_PROTEIN])
			temp.setParentProtein(tsv.getValStr(i, IonFinder::PARENT_PROTEIN));
		if(foundOptionalCols[IonFinder::PARENT_DESCRIPTION])
			temp.setParentDescription(tsv.getValStr(i, IonFinder::PARENT_DESCRIPTION));
		if(foundOptionalCols[IonFinder::MATCH_DIRECTION])
			temp.setMatchDirection(Dtafilter::Scan::strToMatchDirection(tsv.getValStr(i, IonFinder::MATCH_DIRECTION)));
        if(foundOptionalCols[IonFinder::FORMULA])
            temp.setFormula(tsv.getValStr(i, IonFinder::FORMULA));
		if(foundOptionalCols[IonFinder::FULL_SEQUENCE])
			temp.setFullSequence(tsv.getValStr(i, IonFinder::FULL_SEQUENCE));
		if(foundOptionalCols[IonFinder::UNIQUE])
			temp.setUnique(tsv.getValBool(i, IonFinder::UNIQUE));
		if(foundOptionalCols[IonFinder::CHARGE])
			temp.getPrecursor().setCharge(tsv.getValInt(i, IonFinder::CHARGE));
		if(foundOptionalCols[IonFinder::SCORE])
			temp.setXcorr(tsv.getValStr(i, IonFinder::SCORE));
		if(foundOptionalCols[IonFinder::PRECURSOR_MZ])
			temp.getPrecursor().setMZ(tsv.getValStr(i, IonFinder::PRECURSOR_MZ));
		if(foundOptionalCols[IonFinder::PRECURSOR_SCAN])
            temp.getPrecursor().setScan(tsv.getValStr(i, IonFinder::PRECURSOR_SCAN));
		
		//reverse match filter
		if(skipReverse && temp.getMatchDirection() == Dtafilter::Scan::MatchDirection::REVERSE)
			continue;
		
		//mod filter
		if((modFilter == 0 && !temp.isModified()) ||
		   (modFilter == 2 && temp.isModified()))
			continue;
		
		scans.push_back(temp);
	}
	
	return true;
}