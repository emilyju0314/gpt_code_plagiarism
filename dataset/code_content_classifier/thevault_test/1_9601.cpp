void MuseRecord::zerase(string& inout, int num) {
	int len = (int)inout.size();
	if (num >= len) {
		inout = "";
	} else {
		for (int i=num; i<=len; i++) {
			inout[i-num] = inout[i];
		}
	}
	inout.resize(inout.size() - num);
}