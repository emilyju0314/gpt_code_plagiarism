bool StudentDB::check_duplicate_social_security_number(string ssn) {
	
	// Pointer to traverse the list
	//student_element *current;
	// Pointer just before current
	//student_element *trail_current;

	Student_list_pointer p = database.begin();
	
	while(p != database.end()) {
		if(((*p)->get_ssn()) == ssn) {
			return false;
		}
		p++;
	}

//	if(database==NULL) {
/*
		cout << "Student database is empty." << endl;
		cout << "This social security number is not duplicated." << endl;
*/
/*
		return true;
	}else{
		current = database;

		while(current != NULL) {
			if(strcmp(current->value->get_ssn().c_str(),
				ssn.c_str()) == 0) {

				return false;
			}else{
				trail_current = current;
				current = current -> next;
			}
		}
	}
*/
	return true;
}