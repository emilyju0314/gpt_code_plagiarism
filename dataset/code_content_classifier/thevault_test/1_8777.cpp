bool StudentDB::export_database(string outputfilename) {
	
	// Create output file stream
	ofstream outputfile;
	/**
	 * Convert outputfilename to string in C so that the file I/O function
	 * in the C++ library can be utilised
	 */
	outputfile.open(outputfilename.c_str());
	// Assertion to check if the output file was opened properly
	if(outputfile == NULL) {
		cout << "Output file, with the filename " << outputfilename
			<< ", does not exist!" << endl;
		return false;
	}
	
	
	// Left align the data
	outputfile.setf(ios::left);
	// Print the student records...
	
	// Pointer to traverse the list
	//student_element *current;
	// Pointer just before current
	//student_element *trail_current;

	Student_list_pointer p = database.begin();
	while(p != database.end()) {
		outputfile.width(16);
		outputfile << (*p) -> get_lastname();
		outputfile.width(16);
		outputfile << (*p) -> get_firstname();
		outputfile.width(16);
		outputfile << (*p) -> get_ssn();
		outputfile.width(16);
		outputfile << (*p) -> get_phone();
		outputfile.width(16);
		outputfile << (*p) -> get_age();
		outputfile << endl;

		p++;
	}

	outputfile << endl;
	
	// Close the output filestream
	outputfile.close();
	return true;
}