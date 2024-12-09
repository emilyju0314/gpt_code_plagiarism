string Provider::getMatchJson(const map<string, string>& headers) {
	string result;
	char *json = new char[JSON_BUFFER_LENGTH];
    fiftyoneDegreesDeviceOffsets *offsets = matchForHttpHeaders(&headers, 0, 0);
    fiftyoneDegreesProcessDeviceOffsetsJSON(
		provider.active->dataSet,
        offsets,
        json,
        JSON_BUFFER_LENGTH);
	result.assign(json);
	delete json;
	return result;
}