bool Tool_extract::run(HumdrumFile& infile) {
	initialize(infile);
	processFile(infile);
	// Re-load the text for each line from their tokens.
	// infile.createLinesFromTokens();
	return true;
}