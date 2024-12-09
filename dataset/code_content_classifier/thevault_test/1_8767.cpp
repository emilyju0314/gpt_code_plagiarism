void Undergraduate::display() {
	cout.setf(ios::left);
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << get_lastname();
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << get_firstname();
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << get_ssn();
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << get_phone();
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << get_age();
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << get_major();
	cout.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	cout << get_minor() << endl;
}