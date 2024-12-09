int HumdrumFileStream::readSingleSegment(HumdrumFileSet& infiles) {
	infiles.clear();
	HumdrumFile* infile = new HumdrumFile;
	int status = getFile(*infile);
	if (!status) {
		delete infile;
	} else {
		infiles.appendHumdrumPointer(infile);
	}
	return status;
}