const char* Match::getValuePointer(int requiredPropertyIndex) {
	const char *value = NULL;
	if (requiredPropertyIndex >= 0 &&
		requiredPropertyIndex <
		fiftyoneDegreesGetRequiredPropertiesCount(offsets->active->dataSet)) {
		value = fiftyoneDegreesGetValuePtrFromOffsets(
			offsets->active->dataSet,
			offsets,
			requiredPropertyIndex);
	}
	return value;
}