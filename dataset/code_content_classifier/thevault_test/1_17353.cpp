void Provider::initAvailableproperties() {
	const char *propertyName;
    for (int requiredPropetyIndex = 0;
		requiredPropetyIndex <
		fiftyoneDegreesGetRequiredPropertiesCount(provider.active->dataSet);
        requiredPropetyIndex++) {
		propertyName = fiftyoneDegreesGetRequiredPropertiesNames(
			provider.active->dataSet)[requiredPropetyIndex];
        availableProperties.insert(
            availableProperties.end(),
            string(propertyName));
    }
}