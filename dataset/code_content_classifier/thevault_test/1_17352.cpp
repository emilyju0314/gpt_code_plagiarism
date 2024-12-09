void Provider::initHttpHeaders() {
	for (int httpHeaderIndex = 0;
		httpHeaderIndex <
		fiftyoneDegreesGetHttpHeaderCount(provider.active->dataSet);
		httpHeaderIndex++) {
        httpHeaders.insert(
            httpHeaders.end(),
			string(GET_HTTP_HEADER_NAME(
				provider.active->dataSet,
				httpHeaderIndex)));
	}
}