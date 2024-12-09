bool Match::getValueAsBool(const char* propertyName) {
	return getValueAsBool(
		fiftyoneDegreesGetRequiredPropertyIndex(
			offsets->active->dataSet, 
			propertyName));
}