void Provider::buildArray(int offset, map<string, vector<string> > *result) {
	int requiredPropertyIndex;
	string *propertyName;
	for (requiredPropertyIndex = 0;
		requiredPropertyIndex <
		fiftyoneDegreesGetRequiredPropertiesCount(provider.active->dataSet);
        requiredPropertyIndex++) {
        const char *value = fiftyoneDegreesGetValue(
			provider.active->dataSet,
        	offset,
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