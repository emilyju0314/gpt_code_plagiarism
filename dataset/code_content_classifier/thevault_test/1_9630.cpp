void Tool_gasparize::fixBarlines(HumdrumFile& infile) {
	fixFinalBarline(infile);
	HumRegex hre;

	for (int i=0; i<infile.getLineCount(); i++) {
		if (!infile[i].isBarline()) {
			continue;
		}
		if (infile[i].getDurationToEnd() == 0) {
			break;
		}
		for (int j=0; j<infile[i].getFieldCount(); j++) {
			HTp token = infile.token(i, j);
			if (token->find("==") == string::npos) {
				continue;
			}
			if (hre.search(token, "^==(\\d*)")) {
				string text = "=";
				text += hre.getMatch(1);
				text += "||";
				token->setText(text);
			}
		}
	}
}