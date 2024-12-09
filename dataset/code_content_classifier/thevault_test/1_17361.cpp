Match* Provider::getMatchWithTolerances(
	const char* userAgent,
	int userAgentLength,
	int drift,
	int difference) {
	fiftyoneDegreesDeviceOffsets* offsets =
		fiftyoneDegreesProviderCreateDeviceOffsets(&provider);
	offsets->size = 1;
	fiftyoneDegreesSetDeviceOffsetFromArrayWithTolerances(
		provider.active->dataSet,
		userAgent,
		userAgentLength,
		0,
		offsets->firstOffset,
		drift,
		difference);
	Match *result = new Match(offsets);
	return result;
}