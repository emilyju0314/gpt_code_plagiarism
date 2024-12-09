void printLigatureCandidate(HTp partname, HTp starting, HTp ending) {
	HumdrumFile* infile = starting->getOwner()->getOwner();
	cout << m_barnum[starting->getLineIndex()];
	if (partname) {
		cout << "\t" << partname->substr(3);
	} else {
		cout << "\t";
	}
	cout << "\t" << infile->getFilenameBase();
	cout << endl;
}