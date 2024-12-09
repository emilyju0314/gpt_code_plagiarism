int Match::getValueAsInteger(const char* propertyName) {
	return getValueAsInteger(
		fiftyoneDegreesGetRequiredPropertyIndex(
			offsets->active->dataSet, 
			propertyName));
}