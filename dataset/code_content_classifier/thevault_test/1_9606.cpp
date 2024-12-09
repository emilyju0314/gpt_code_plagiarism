void Tool_restfill::fillInRests(HTp start) {
	HTp current = start;
	HTp firstcell = NULL;
	int founddata = false;
	bool foundcontent = false;
	HumNum lasttime = 0;
	HumNum currtime = 0;
	HumNum duration = 0;
	while (current) {
		if (current->isBarline()) {
			if (firstcell) {
				lasttime = firstcell->getDurationFromStart();
			}
			currtime = getNextTime(current);
			if (firstcell && founddata && !foundcontent) {
				duration = currtime - lasttime;
				addRest(firstcell, duration);
			}
			firstcell = NULL;
			founddata = false;
			foundcontent = false;
			current = current->getNextToken();
			lasttime = currtime;
			continue;
		}
		if (!current->isData()) {
			current = current->getNextToken();
			continue;
		}
		if (current->getDuration() == 0) {
			// grace-note line, so ignore
			current = current->getNextToken();
			continue;
		}
		founddata = true;
		if (!current->isNull()) {
			foundcontent = true;
		}
		if (!firstcell) {
			firstcell = current;
		}
		current = current->getNextToken();
	}
}