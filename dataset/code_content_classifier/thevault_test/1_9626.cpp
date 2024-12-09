void Tool_gasparize::addTerminalLongs(HumdrumFile& infile) {
	int scount = infile.getStrandCount();
	for (int i=0; i<scount; i++) {
		HTp cur = infile.getStrandEnd(i);
		if (*cur != "*-") {
			continue;
		}
		if (!cur->isKern()) {
			continue;
		}
		while (cur) {
			if (!cur->isData()) {
				cur = cur->getPreviousToken();
				continue;
			}
			if (cur->isNull()) {
				cur = cur->getPreviousToken();
				continue;
			}
			if (cur->isRest()) {
				cur = cur->getPreviousToken();
				continue;
			}
			if (cur->isSecondaryTiedNote()) {
				cur = cur->getPreviousToken();
				continue;
			}
			if (cur->find("l") != string::npos) {
				// already marked so do not do it again
				break;
			}
			// mark this note with "l"
			string newtext = *cur;
			newtext += "l";
			cur->setText(newtext);
			break;
		}
	}
}