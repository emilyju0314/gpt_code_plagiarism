fiftyoneDegreesDeviceOffsets* Provider::matchForHttpHeaders(
		const map<string, string> *headers,
		int drift,
		int difference) {
	int headerIndex = 0;
	fiftyoneDegreesDeviceOffsets* offsets =
		fiftyoneDegreesProviderCreateDeviceOffsets(&provider);
	const char *httpHeaderName =
		GET_HTTP_HEADER_NAME(provider.active->dataSet, headerIndex);
	while (httpHeaderName != NULL) {
		map<string, string>::const_iterator httpHeaderValue =
			headers->find(string(httpHeaderName));
		if (httpHeaderValue != headers->end()) {
			fiftyoneDegreesSetDeviceOffsetWithTolerances(
				provider.active->dataSet,
				httpHeaderValue->second.c_str(),
				headerIndex,
				&offsets->firstOffset[offsets->size],
				drift,
				difference);
            offsets->size++;
		}
		headerIndex++;
		httpHeaderName =
			GET_HTTP_HEADER_NAME(provider.active->dataSet, headerIndex);
	}
	return offsets;
}