bool StudentDB::import_database(string inputfilename) {
	
	// Create input file stream
	ifstream inputfile;
	// Open the input file
	inputfile.open(inputfilename.c_str());
	// Assertion to check if the input file exist
	if(inputfile == NULL) {
		cout << "Input file, with the filename " << inputfilename
			<< ", does not exist!" << endl;
		return false;
	}
	
	
	/**
	 * Declare and instantiate some variables to temporarily store data
	 * before processing them
	 */
	// Last name of the student
	string lastname="";
	// First name of the student
	string firstname="";
	// Student's social security number
	string socialsecuritynumber="";
	// Student's phone number in the united states
	string phonenumber="";
	// Student's age
	int studentage=0;
	// Number of errors found in the student record
	int errors=0;
	// Current index in which correct student record should be stored
	int correct_index;
	/**
	 * Temporary store the social security number so that it's dashes can be
	 * removed without modifying the social_security_number field of the
	 * student
	 */
	string temp_ssn="";	
	/**
	 * Current index of the record of student particulars
	 * that is being enumerated
	 */
	int i=0;
	// Start processing the data in the table
	while((inputfile != NULL) && (i<MAXIMUM_NUMBER_OF_STUDENTS)) {
//cout << "process me" <<endl;
		// Stop processing the input file once its end has been reached
		if ( (inputfile >> lastname	>> firstname >> socialsecuritynumber
			>> phonenumber >> studentage) == NULL) {
			break;
		}
//cout << "checking" <<endl;
		i++;		
		/**
		 * Check if the student particulars are valid...
		 * If any of the student particulars is invalid,
		 * ignore this current line in the input file and
		 * skip to the next
		 */
		if(!check_lastname(lastname)) {
			cout << "\t Ignoring Record Number " << i <<
				" - bad last name" << endl;
			cout << "\t\t Last name of the student should only contain "
				<< "alphabets" << endl;
			errors++;
			continue;
		}else if(!check_firstname(firstname)) {
			cout << "\t Ignoring Record Number " << i <<
				" - bad first name" << endl;
			cout << "\t\t First name of the student should only contain "
				<< "alphabets" << endl;
			errors++;
			continue;
		}else if(!check_socialsecuritynumber(socialsecuritynumber)) {
			cout << "\t Ignoring Record Number " << i <<
				" - bad social security number" << endl;
			cout << "\t\t Security numbers should contain dashes at the "
				<< "4th and 7th characters, and digits otherwise" << endl;
			errors++;
			continue;
		}else if(!check_phonenumber(phonenumber)) {
			cout << "\t Ignoring Record Number " << i 
				<< " - bad phone number" << endl;
			cout << "\t\t Phone numbers should be given in this format: "
				<< "(XXX)XXX-XXXX, where each X is a digit" << endl;
			errors++;
			continue;
		}else if(!check_studentage(studentage)) {
			cout << "\t Ignoring Record Number " << i << " - bad age" << endl;
			cout << "\t\t Age of the student should be between 1 and 120, "
				<< "inclusive" << endl;
			errors++;
			continue;
/*
		}else if(!check_duplicate_social_security_number(socialsecuritynumber)) {
			cout << "\t Ignoring Record Number " << i
				<< " - duplicate social security number" << endl;
			errors++;
			continue;
*/
		}
//cout << "Checks passed" << endl;		
		/**
		 * Student's first and last names, social security number, phone
		 * number, and age are valid...
		 * Enter these details into the appropriate place in the records
		 */
		correct_index=i-errors-1;
		// Creating a student record
		Student *tempStudent = new Student();
		tempStudent->set_lastname(lastname);
//cout << "Modify last name of temp student" << endl;
		tempStudent->set_firstname(firstname);
		tempStudent->set_ssn(socialsecuritynumber);
		tempStudent->set_phone(phonenumber);
		tempStudent->set_age(studentage);
//cout << "End Modification" << endl;
		if(!add_student(tempStudent)) {
//cout << "Error adding student from input file" << endl;
			continue;
		}
//cout << "Next" << endl;
	}
	
	cout << endl;
	cout << "Processed " << i << " student records" << endl;
	cout << (errors+1) << " errors were found" << endl;
	cout << endl;
	// Determine the number of correct student records
	number_correct_records=i-errors;
	
	// Close the input filestream
	inputfile.close();
	
	return true;
}