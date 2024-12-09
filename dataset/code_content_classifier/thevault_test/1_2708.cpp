view::StringListViewRef loadPrintAndMergeLists () {
	model::StringListRef  	listRef = loadList ();

	if (listRef == NULL) {
		cout << "loadPrintAndMergeLists: listRef is NULL";
		return NULL;
	}
	view::StringListViewRef listViewRef = new view::StringListView (listRef);

	printAndSortList (listViewRef);
	mergeAdditionalValues (listViewRef);
	return listViewRef;
}