void Undergraduate::write_to_stream (ofstream & outputfile) {
	// Left align the data
	outputfile.setf(ios::left);
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << "Undergraduate";
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << Student::get_lastname();
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << get_firstname();
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << get_ssn();
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << get_phone();
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << get_age();
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << get_major();
	outputfile.width(MAXIMUM_NUMBER_OF_CHARACTERS);
	outputfile << get_minor() << endl;
	//outputfile << endl;
}