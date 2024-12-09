double Match::getValueAsDouble(int requiredPropertyIndex) {
	const char *value = getValuePointer(requiredPropertyIndex);
	if (value != NULL) {
		return strtod(value, NULL);
	}
	return 0;
}