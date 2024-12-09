void StudentDB::print_header() {
	cout.setf(ios::left);
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << "Last Name";
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << "First Name";
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << "Social Security #";
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << "Phone #";
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << "Age" << endl;
}