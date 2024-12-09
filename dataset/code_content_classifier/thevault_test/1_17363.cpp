Match* Provider::getMatchWithTolerances(
	const string& userAgent,
	int drift,
	int difference) {
	return getMatchWithTolerances(userAgent.c_str(), -1, drift, difference);
}