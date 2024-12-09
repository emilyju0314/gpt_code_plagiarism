model::StringListRef loadList () {
	fileIO::FileLoader 		myLoader (STRING_LIST_FILE_NAME);
	model::StringListRef  	listRef;

	try {
		listRef = myLoader.createStringList();
	} catch (int error) {
		return NULL;
	}
	return listRef; // Success
}