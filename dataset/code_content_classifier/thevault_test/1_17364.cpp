string Provider::getMatchJson(const char* userAgent) {
    string result;
    char *json = new char[JSON_BUFFER_LENGTH];
    fiftyoneDegreesProcessDeviceJSON(
		provider.active->dataSet,
        fiftyoneDegreesGetDeviceOffset(provider.active->dataSet, userAgent),
        json,
        JSON_BUFFER_LENGTH);
    result.assign(json);
    delete json;
    return result;
}