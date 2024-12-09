void displayBag(const unique_ptr<LinkedBag<string>>& bag) {
	cout << "\n !Display bag: ";
	auto bagItems = make_unique<vector<string>>(bag->toVector());

	vector<string>::const_iterator cItr;
	for (cItr = bagItems->begin(); cItr != bagItems->end(); cItr++) {
		cout << *cItr << " ";
	}

	cout << "\n  -----------> " << bagItems->size() << " item(s) total";
	cout << endl;
}