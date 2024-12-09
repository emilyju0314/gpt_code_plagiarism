void processPart(HumdrumFile& infile, HTp partstart) {
	vector<HTp> notelist;
	HTp partname = getNoteList(notelist, partstart);
	vector<HumNum> durations(notelist.size());
	for (int i=0; i<(int)notelist.size(); i++) {
		durations[i] = notelist[i]->getTiedDuration();
	}

	HumNum mindur(8, 3);
	HumNum maxdur(6, 1);
	for (int i=0; i<(int)durations.size()-1; i++) {
		if (notelist[i]->isRest()) {
			continue;
		}
		if (notelist[i+1]->isRest()) {
			continue;
		}
		if ((durations[i] >= mindur) && (durations[i] <= maxdur) &&
		    (durations[i+1] >= mindur) && (durations[i+1] <= maxdur)) {
			// exclude cases where the pitch is repeated
			int pitch1 = Convert::kernToMidiNoteNumber(notelist[i]);
			int pitch2 = Convert::kernToMidiNoteNumber(notelist[i+1]);
			if (pitch1 == pitch2) {
				continue;
			}
			bool hastext1 = hasText(notelist[i]);
			bool hastext2 = hasText(notelist[i+1]);
			if (hastext1 && !hastext2) {
				printLigatureCandidate(partname, notelist[i], notelist[i+1]);
			}
		}
	}
}