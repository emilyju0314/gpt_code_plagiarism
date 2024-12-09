Undergraduate::Undergraduate(string firstname, string lastname, string ssn,
	string phone_num, int age, string major_title, string minor_title)
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
		
		set_major(major_title);
		set_minor(minor_title);
	}else{
		cout << "Default constructor of the Undergraduate student has errors"
			<< endl;
	}
}