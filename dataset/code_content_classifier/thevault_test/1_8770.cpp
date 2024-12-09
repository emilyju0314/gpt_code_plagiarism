void write_output(string outputfilename, student student_particulars[]) {
	
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
	}
	
	
	// Left align the data
	outputfile.setf(ios::left);
	// Print the student records
	for(int i=0; i<number_correct_records; i++) {
		outputfile.width(16);
		outputfile << student_particulars[i].last_name;
		outputfile.width(16);
		outputfile << student_particulars[i].first_name;
		outputfile.width(16);
		outputfile << student_particulars[i].social_security_number;
		outputfile.width(16);
		outputfile << student_particulars[i].phone_number;
		outputfile.width(16);
		outputfile << student_particulars[i].age;
	}
	outputfile << endl;
	
	// Close the output filestream
	outputfile.close();
}