void mergeAdditionalValues (view::StringListViewRef listViewRef) {
	model::StringListRef  	listRef 			= listViewRef->getStringList();
	model::StringListRef 	insertListRef 		= new model::StringList ();
	view::StringListViewRef insertListViewRef 	= new view::StringListView (insertListRef);

	string additionalValues [] = {"Strawberry", "Kiwi", "Raspberry"};

	insertListRef->append (3, additionalValues);
	insertListViewRef->printNames ("Insert list");

	cout << "Sorting the insert list\n";
	insertListRef->sort ();
	insertListViewRef->printNames ("Insert list");

	cout << "\nMerging...\n";
	listRef->mergeStringList (insertListRef);

	listViewRef->printNames ("List after merge");
	insertListViewRef->printNames ("Insert list is unchanged (After merge)");

	cout << "\nThe additional model and view will be destructed\n";
}