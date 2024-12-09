bool StudentDB::add_student(Student * student_details) {
	// Pointer to traverse the list
	//student_element *current;
	// Pointer just before current
	//student_element *trail_current;
		
	// Allocate a new student_element
	//student_element *newelement = new student_element();
	// Place the student pointer into "value" and hook up the pointers
	//newelement->value = student_details;
	//newelement->next = NULL;

	// List is empty and uninitialized
	Student_list_pointer p = database.begin();
	
	if(get_number_correct_records()==0) {
		database.push_back(student_details);
		increment_index_of_last_element();
		set_number_correct_records(get_index_of_last_element()+1);
//cout<<"if statement"<<endl;
		return true;
	}
	
	while(p != database.end()) {
		if(strcmp((*p)->get_ssn().c_str(),
			student_details->get_ssn().c_str()) >0) {
			
			database.insert(p, student_details);
//cout<<"while-if statement"<<endl;
			return true;
		}else if(strcmp((*p)->get_ssn().c_str(),
			student_details->get_ssn().c_str()) == 0) {
			
			cout << "A student with the social security number, "
				<< (*p)->get_ssn()
				<< ", already exists in the database"
				<< endl;
			return false;
		}
		p++;
//cout<<"while-p++"<<endl;
	}
//cout<<"end while loop"<<endl;
	database.push_back(student_details);
	increment_index_of_last_element();
	set_number_correct_records(get_index_of_last_element()+1);
	return true;
}