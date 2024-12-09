vector<bool> Tool_chantize::getTerminalRestStates(HumdrumFile& infile) {
	vector<bool> output(infile.getLineCount(), false);

	for (int i=infile.getLineCount() - 1; i>=0; i--) {
		if (!infile[i].isData()) {
			continue;
		}
		HTp token = infile.token(i, 0);
		if (token->isRest()) {
			output[i] = true;
		} else {
			break;
		}
	}

	return output;

}