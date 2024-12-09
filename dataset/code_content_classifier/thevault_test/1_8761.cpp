Undergraduate::Undergraduate(string firstname, string lastname, string ssn,
	string phone_num, int age)
{
	/**
	 * Automatically initialize the Student Attributes by default
	 * Student constructor
	 */
	if(set_ssn(ssn) &&
		set_lastname(lastname) &&
		set_firstname(firstname) &&
		set_phone(phone_num) &&
		set_age(age)) {
		
		// Do nothing...
	}else{
		cout << "Default constructor of the Undergraduate student has errors"
			<< endl;
	}
	
	major = "BME";
	minor = "PHIL";
}