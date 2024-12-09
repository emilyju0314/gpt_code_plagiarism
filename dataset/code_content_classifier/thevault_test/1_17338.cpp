string Match::getValue(int requiredPropertyIndex) {
	string result;
	const char *value = getValuePointer(requiredPropertyIndex);
	if (value != NULL) {
		result.assign(value);
	}
	return result;
}