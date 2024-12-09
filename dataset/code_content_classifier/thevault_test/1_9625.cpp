void Tool_gasparize::removeDoubledAccidentals(HumdrumFile& infile) {
	HumRegex hre;
	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isData()) {
			continue;
		}
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			if (!token->isKern()) {
				continue;
			}
			if (token->isNull()) {
				continue;
			}
			if (token->isRest()) {
				continue;
			}
			if (token->find("--") != string::npos) {
				string text = *token;
				hre.replaceDestructive(text, "-", "--", "g");
			} else if (token->find("--") != string::npos) {
				string text = *token;
				hre.replaceDestructive(text, "#", "##", "g");
			}
		}
	}
}