void Provider::buildArray(
		fiftyoneDegreesDeviceOffsets *offsets,
		map<string, vector<string> > *result) {
	int requiredPropertyIndex;
	string *propertyName;
	for (requiredPropertyIndex = 0;
		requiredPropertyIndex <
		fiftyoneDegreesGetRequiredPropertiesCount(provider.active->dataSet);
        requiredPropertyIndex++) {
        const char *value = fiftyoneDegreesGetValuePtrFromOffsets(
			provider.active->dataSet,
        	offsets,
        	requiredPropertyIndex);
        if (value != NULL) {
            propertyName = new string(
				fiftyoneDegreesGetRequiredPropertiesNames(
					provider.active->dataSet)[requiredPropertyIndex]);
            vector<string> *values = &(result->operator[](*propertyName));
            values->insert(values->begin(), string(value));
        }
	}
}