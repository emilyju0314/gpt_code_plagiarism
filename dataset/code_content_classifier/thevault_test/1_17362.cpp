Match* Provider::getMatchWithTolerances(
	const char* userAgent,
	int drift,
	int difference) {
	return getMatchWithTolerances(userAgent, -1, drift, difference);
}