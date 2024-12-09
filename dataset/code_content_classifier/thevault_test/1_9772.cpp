int HumdrumFileBase::getExinterpCount(const string& exinterp) {
	vector<HTp> spinestarts;
	getSpineStartList(spinestarts, exinterp);
	return (int)spinestarts.size();
}