bool sortTokenPairsByLineIndex(const TokenPair& a, const TokenPair& b) {
	if (a.first->getLineIndex() < b.first->getLineIndex()) {
		return true;
	}
	if (a.first->getLineIndex() == b.first->getLineIndex()) {
		if (a.first->getFieldIndex() < b.first->getFieldIndex()) {
			return true;
		}
	}
	return false;
}