bool Tool_autostem::run(HumdrumFile& infile) {
	initialize(infile);
	if (m_quit) {
		return true;
	}
	if (removeQ || overwriteQ) {
		removeStems(infile);
		if (removeQ) {
			infile.createLinesFromTokens();
			return true;
		}
	}
	bool status = autostem(infile);
	// Re-load the text for each line from their tokens.
	if (status) {
		infile.createLinesFromTokens();
		return true;
	} else {
		return false;
	}
}