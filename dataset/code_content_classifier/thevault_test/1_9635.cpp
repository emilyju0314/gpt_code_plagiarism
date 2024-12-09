bool Tool_half::run(HumdrumFile& infile) {
	processFile(infile);

	// Re-load the text for each line from their tokens.
	infile.createLinesFromTokens();

	// Need to adjust the line numbers for tokens for later
	// processing.
	m_humdrum_text << infile;
	return true;
}