vector<string> Match::getValues(const char *propertyName) {
	return getValues(fiftyoneDegreesGetRequiredPropertyIndex(
		offsets->active->dataSet,
		propertyName));
}