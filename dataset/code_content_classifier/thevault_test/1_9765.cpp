bool HumdrumFileBase::readStringCsv(const char* contents,
		const string& separator) {
	stringstream infile;
	infile << contents;
	return readCsv(infile, separator);
}