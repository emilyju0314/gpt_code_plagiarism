void StudentDB::display_all() {
	// Print the header...
	print_header();

	cout.setf(ios::left);
	
	// Pointer to traverse the list
	//student_element *current;
	// Pointer just before current
	//student_element *trail_current;

	Student_list_pointer p =database.begin();
	while(p != database.end()) {
		cout.width(16);
		cout << (*p) -> get_lastname();
		cout.width(16);
		cout << (*p) -> get_firstname();
		cout.width(16);
		cout << (*p) -> get_ssn();
		cout.width(16);
		cout << (*p) -> get_phone();
		cout.width(16);
		cout << (*p) -> get_age() << endl;
		p++;
	}
}