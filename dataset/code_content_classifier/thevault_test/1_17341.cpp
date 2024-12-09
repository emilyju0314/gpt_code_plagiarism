int Match::getValueAsInteger(int requiredPropertyIndex) {
	const char *value = getValuePointer(requiredPropertyIndex);
	if (value != NULL) {
		return atoi(value);
	}
	return 0;
}