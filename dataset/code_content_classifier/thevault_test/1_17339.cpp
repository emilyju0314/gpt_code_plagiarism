string Match::getValue(const char* propertyName) {
	return getValue(
		fiftyoneDegreesGetRequiredPropertyIndex(
			offsets->active->dataSet,
			propertyName));
}