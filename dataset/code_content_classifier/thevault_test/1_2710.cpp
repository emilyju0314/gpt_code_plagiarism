void printAndSortList (view::StringListViewRef listViewRef) {
	model::StringListRef  	listRef = listViewRef->getStringList();

	listViewRef->printNames ("List loaded from file");
	cout << "Sorting the list\n";
	listRef->sort ();
	listViewRef->printNames ("List loaded from file");
}