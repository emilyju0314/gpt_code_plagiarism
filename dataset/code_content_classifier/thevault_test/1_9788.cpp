string HumdrumFileBase::getMergedSpineInfo(vector<string>& info, int starti,
		int extra) {
	string output;
	int len1;
	int len2;
	if (extra < 1) {
		// Strange if get here.
		return info[starti];
	} else if (extra == 1) {
		len1 = (int)info[starti].size();
		len2 = (int)info[starti+1].size();
		if (len1 == len2) {
			if (info[starti].substr(0, len1-1) ==
					info[starti+1].substr(0,len2-1)) {
				output = info[starti].substr(1, len1-3);
				return output;
			}
		}
		output = info[starti] + " " + info[starti+1];
		return output;
	}
	// Generalized code for simplifying up to 4 subspines at once.
	// Not fully generlized so that the subspines will always be
	// simplified if not merged in a simple way, though.
	vector<string> newinfo;
	int i;
	for (i=0; i<=extra; i++) {
		newinfo.push_back(info.at(starti+i));
	}
	for (i=1; i<(int)newinfo.size(); i++) {
		int len1 = (int)newinfo[i-1].size();
		int len2 = (int)newinfo[i].size();
		if (len1 != len2) {
			continue;
		}
		if (newinfo[i-1].compare(0, len1-1, newinfo[i], 0, len2-1) == 0) {
			newinfo[i-1] = "";
			newinfo[i] = newinfo[i].substr(1, len2-3);
		}
	}
	vector<string> newinfo2;
	for (i=0; i<(int)newinfo.size(); i++) {
		if (newinfo[i].empty()) {
			continue;
		}
		newinfo2.push_back(newinfo[i]);
	}
	for (i=1; i<(int)newinfo2.size(); i++) {
		int len1 = (int)newinfo2[i-1].size();
		int len2 = (int)newinfo2[i].size();
		if (len1 != len2) {
			continue;
		}
		if (newinfo2[i-1].compare(0, len1-1, newinfo2[i], 0, len2-1) == 0) {
			newinfo2[i-1] = "";
			newinfo2[i] = newinfo2[i].substr(1, len2-3);
		}
	}
	newinfo.resize(0);
	for (i=0; i<(int)newinfo2.size(); i++) {
		if (newinfo2[i].empty()) {
			continue;
		}
		newinfo.push_back(newinfo2[i]);
	}
	output = newinfo[0];
	for (int i=1; i<(int)newinfo.size(); i++) {
		output += " " + info.at(i);
	}
	return output;
}