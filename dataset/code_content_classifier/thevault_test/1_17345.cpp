vector<string> Match::getValues(int requiredPropertyIndex) {
	vector<string> result;
	if (requiredPropertyIndex >= 0 &&
		requiredPropertyIndex < 
			fiftyoneDegreesGetRequiredPropertiesCount(
				offsets->active->dataSet)) {
		char *start = (char*)getValuePointer(requiredPropertyIndex);
		if (start != NULL) {
			char *current = start, *last = start;
			while (*current != 0) {
				if (*current == '|') {
					result.insert(
						result.end(),
						string(last, current - last));
					last = current + 1;
				}
				current++;
			}
			result.insert(
				result.end(),
				string(last, current - last));
		}
	}
	return result;
}