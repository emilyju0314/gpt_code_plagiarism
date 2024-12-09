bool Tool_chantize::run(HumdrumFile& infile) {
	processFile(infile);

	// Re-load the text for each line from their tokens.
	infile.createLinesFromTokens();
	outputFile(infile);
	return true;
}