Undergraduate::Undergraduate(string ssn, string lastname, int age)
{
	/**
	 * Automatically initialize the Student Attributes by default
	 * Student constructor
	 */
	if(set_ssn(ssn) &&
		set_lastname(lastname) &&
		set_firstname("Firstname") &&
		set_phone("(999)999-9999") &&
		set_age(age)) {
		
		// Do nothing...
	}else{
		cout << "Default constructor of the Undergraduate student has errors"
			<< endl;
	}
	
	major = "BME";
	minor = "PHIL";
}