static bool readEntry(Entry& e, std::FILE *file) {
	int endChecker = std::fscanf(file, "\"%d\";", &e.id);
	
	if (endChecker < 0) {
		e.valid = false;
		return false;
	}

	readStringField(e.title, file, TITLE_CHAR_MAX);
	std::fscanf(file, "\"%d\";", &e.year);
	readStringField(e.authors, file, AUTHORS_CHAR_MAX);
	std::fscanf(file, "\"%d\";", &e.citations);
	readStringField(e.updateTimestamp, file, TIMESTAMP_CHAR_MAX);
	readStringField(e.snippet, file, SNIPPET_CHAR_MAX);
	
	e.valid = true;
	return true;
}