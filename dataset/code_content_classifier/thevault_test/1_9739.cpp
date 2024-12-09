int HumdrumFileSet::readAppendFile(const string& filename) {
	ifstream indata;
	indata.open(filename);
	string contents((istreambuf_iterator<char>(indata)), istreambuf_iterator<char>());
	HumdrumFileStream instream(contents);
	return readAppend(instream);
}