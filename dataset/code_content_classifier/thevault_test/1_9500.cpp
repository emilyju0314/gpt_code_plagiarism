int Tool_imitation::compareSequences(vector<NoteCell*>& attack1,
		vector<double>& seq1, int i1, vector<NoteCell*>& attack2,
		vector<double>& seq2, int i2) {
	int count = 0;
	// sequences cannot start with rests
	if (Convert::isNaN(seq1.at(i1)) || Convert::isNaN(seq2.at(i2))) {
		return count;
	}
	if (m_nozero) {
		// exclude matches that start at the same time.
		if (attack1.at(i1)->getToken()->getDurationFromStart() == attack2.at(i2)->getToken()->getDurationFromStart()) {
			return count;
		}
	} else if (m_onlyzero) {
		// exclude matches that do not start at the same time (parallel motion).
		if (attack1.at(i1)->getToken()->getDurationFromStart() != attack2.at(i2)->getToken()->getDurationFromStart()) {
			return count;
		}
	}

	HumNum dur1;
	HumNum dur2;

	while ((i1+count < (int)seq1.size()) && (i2+count < (int)seq2.size())) {

		if (m_duration) {
			dur1 = attack1.at(i1+count)->getDuration();
			dur2 = attack2.at(i2+count)->getDuration();
			if (dur1 != dur2) {
				break;
			}
		}

		if (Convert::isNaN(seq1.at(i1+count))) {
			// the first voice's interval is to/from a rest
			if (Convert::isNaN(seq2.at(i2+count))) {
				// The seoncd voice's interval is also to/from a rest,
				// so increment count and continue.
				count++;
				continue;
			} else {
				// The second voice's interval is not to/from a rest,
				// so return the current count.
				if (count) {
					return count + 1;
				} else {
					return count;
				}
			}
		} else if (Convert::isNaN(seq2.at(i2+count))) {
			// The second voice's interval is to/from a rest
			// but already know that the first one is not, so return
			// current count;
			if (count) {
				return count + 1;
			} else {
				return count;
			}
		} else if (m_inversion && (seq1.at(i1+count) == -seq2.at(i2+count))) {
         // The two sequences match as inversions at this point, so continue.
			count++;
		} else if ((!m_inversion) && (seq1.at(i1+count) == seq2.at(i2+count))) {
         // The two sequences match at this point, so continue.
			count++;
			continue;
		} else {
			// The sequences do not match so return the current count.
			if (count) {
				return count + 1;
			} else {
				return count;
			}
		}
	}

	if (count) {
		// don't add one for some reaason (this will cause out-of-bounds)
		return count;
	} else {
		return count;
	}
}