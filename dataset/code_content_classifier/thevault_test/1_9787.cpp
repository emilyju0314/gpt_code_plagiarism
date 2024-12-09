bool HumdrumFileBase::adjustSpines(HumdrumLine& line, vector<string>& datatype,
		vector<string>& sinfo) {
	vector<string> newtype;
	vector<string> newinfo;
	int mergecount = 0;
	int i, j;
	for (i=0; i<line.getTokenCount(); i++) {
		if (line.token(i)->isSplitInterpretation()) {
			newtype.resize(newtype.size() + 1);
			newtype.back() = datatype[i];
			newtype.resize(newtype.size() + 1);
			newtype.back() = datatype[i];
			newinfo.resize(newinfo.size() + 2);
			newinfo[newinfo.size()-2] = '(' + sinfo[i] + ")a";
			newinfo[newinfo.size()-1] = '(' + sinfo[i] + ")b";
		} else if (line.token(i)->isMergeInterpretation()) {
			mergecount = 0;
			for (j=i+1; j<line.getTokenCount(); j++) {
				if (line.token(j)->isMergeInterpretation()) {
					mergecount++;
				} else {
					break;
				}
			}
			newinfo.emplace_back(getMergedSpineInfo(sinfo, i, mergecount));
			newtype.push_back(datatype[i]);
			i += mergecount;
		} else if (line.token(i)->isAddInterpretation()) {
			newtype.resize(newtype.size() + 1);
			newtype.back() = datatype[i];
			newtype.resize(newtype.size() + 1);
			newtype.back() = "";
			newinfo.resize(newinfo.size() + 1);
			newinfo.back() = sinfo[i];
			newinfo.resize(newinfo.size() + 1);
			addToTrackStarts(NULL);
			newinfo.back() = to_string(getMaxTrack());
		} else if (line.token(i)->isExchangeInterpretation()) {
			if (i < line.getTokenCount() - 1) {
				if (line.token(i)->isExchangeInterpretation()) {
					// exchange spine information
					newtype.resize(newtype.size() + 1);
					newtype.back() = datatype[i+1];
					newtype.resize(newtype.size() + 1);
					newtype.back() = datatype[i];
					newinfo.resize(newinfo.size() + 1);
					newinfo.back() = sinfo[i+1];
					newinfo.resize(newinfo.size() + 1);
					newinfo.back() = sinfo[i];
				} else {
					return setParseError("ERROR1 in *x calculation");
				}
				i++;
			} else {
				stringstream err;
				err << "ERROR2 in *x calculation" << endl;
				err << "Index " << i << " larger than allowed: "
				     << line.getTokenCount() - 1;
				return setParseError(err);
			}
		} else if (line.token(i)->isTerminateInterpretation()) {
			// store pointer to terminate token in trackends
			m_trackends[m_trackstarts.size()-1].push_back(line.token(i));
		} else if (((string*)line.token(i))->substr(0, 2) == "**") {
			newtype.resize(newtype.size() + 1);
			newtype.back() = line.getTokenString(i);
			newinfo.resize(newinfo.size() + 1);
			newinfo.back() = sinfo[i];
			if (!((m_trackstarts.size() > 1) && (m_trackstarts.back() == NULL))) {
				stringstream err;
				err << "Error: Exclusive interpretation with no preparation "
				     << "on line " << line.getLineIndex()
				     << " spine index " << i << endl;
				err << "Line: " << line;
				return setParseError(err);
			}
			if (m_trackstarts.back() == NULL) {
				addToTrackStarts(line.token(i));
			}
		} else {
			// should only be null interpretation, but doesn't matter
			newtype.resize(newtype.size() + 1);
			newtype.back() = datatype[i];
			newinfo.resize(newinfo.size() + 1);
			newinfo.back() = sinfo[i];
		}
	}

	datatype.resize(newtype.size());
	sinfo.resize(newinfo.size());
	for (i=0; i<(int)newtype.size(); i++) {
		datatype[i] = newtype[i];
		sinfo[i]    = newinfo[i];
	}

	return true;
}