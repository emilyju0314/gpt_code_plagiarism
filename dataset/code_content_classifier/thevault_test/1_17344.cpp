double Match::getValueAsDouble(const char* propertyName) {
	return getValueAsDouble(
		fiftyoneDegreesGetRequiredPropertyIndex(
			offsets->active->dataSet, 
			propertyName));
}