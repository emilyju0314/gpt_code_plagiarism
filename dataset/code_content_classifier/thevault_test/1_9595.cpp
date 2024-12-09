int MuseRecord::getSlurStartColumn(void) {
	int start = 31;
	int stop = getLength() - 1;
	if (stop >= 43) {
		stop = 42;
	}
	int i;
	for (i=start; i<=stop; i++) {
		switch (m_recordString[i]) {
			case '(':   // slur level 1
			case '[':   // slur level 2
			case '{':   // slur level 3
			case 'z':   // slur level 4
				return i+1;  // column is offset from 1
		}
	}

	return -1;
}