void printPedalData(HumdrumFile& infile) { 
	if (LegendQ) {
		cout << "\n";
		cout << "########################################################\n";
		cout << "## LIST OF PEDALING                                   ##\n";
		cout << "##                                                    ##\n";
		cout << "## Meaning of columns:                                ##\n";
		cout << "## 1  PEDAL: Pedal enumeration number.                ##\n";
		cout << "## 2  PTYPE: Type of pedal (0 = off; 1 = on).         ##\n";
		cout << "## 3  BAR:   The measure that the pedal is in.        ##\n";
		cout << "## 4  ABSQ:  The starting time in quarter notes from  ##\n";
		cout << "##           start of music.                          ##\n";
		cout << "## 5  PDUR:  the ending time in quarter notes from    ##\n";
		cout << "##           start of music.                          ##\n";
		cout << "## 6  MFRAC: Fractional position of the pedal in bar. ##\n";
		cout << "########################################################\n";
	}

	// Data column meanings:
	cout << "#PEDAL";
	cout << "\tPTYPE";
	cout << "\tBAR";
	cout << "\tABSQ";
	cout << "\tPDUR";
	cout << "\tMFRAC";
	cout << "\n";

	vector<HTp> pedalseq;
	getPedalTokens(pedalseq, infile);
	for (int i=0; i<(int)pedalseq.size(); i++) {
		HTp pedal = pedalseq[i];
		HTp nextpedal = NULL;
		if (i < (int)pedalseq.size() - 1) {
			nextpedal = pedalseq[i+1];
		}

		// @@PEDAL-# and enumeration of the pedal
		cout << "PEDAL-" << (i+1) << "\t";

		// @@PTYPE: the pedal message type (0 = pedal up, 1 = pedal down)
		if (*pedal == "*ped") {
			cout << "1";
		} else if (*pedal == "*Xped") {
			cout << "0";
		} else {
			cout << "-1";
		}

		// @@BAR: The measure/bar number in which the pedal is locaed.
		cout << "\t" << Barnum[pedal->getLineIndex()];

		// @@ABSQ: the position in the score since the first barline
		HumNum start = getAbsBeat(pedal);
		cout << "\t" << start.getFloat();

		// @@PDUR: the duration to the next pedal mark.  If the current
		// pedal is a pedal down, then the PDUR value is the duration
		// of the sustain.
		if (nextpedal) {
			HumNum duration = nextpedal->getDurationFromStart()
					- pedal->getDurationFromStart();
			cout << "\t" << duration.getFloat();
		} else {
			cout << "\t-1";
		}

		// @@MFRAC: the position in the score since the first barline
		cout << "\t" << getMeasureFraction(pedal).getFloat();

		cout << endl;
	}
}