bool StudentDB::display_student(string ssn) {
	cout.setf(ios::left);
	
	// Pointer to traverse the list
	//student_element *current;
	// Pointer just before current
	//student_element *trail_current;

	Student_list_pointer p = database.begin();
	while(p != database.end()) {
		if(strcmp((*p)->get_ssn().c_str(),
			ssn.c_str()) == 0) {
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
			return true;
		}
		p++;
	}

	return false;
}