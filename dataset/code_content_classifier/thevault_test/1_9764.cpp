bool HumdrumFileBase::readString(const string& contents) {
	stringstream infile;
	infile << contents;
	bool status = read(infile);
	return status;
}