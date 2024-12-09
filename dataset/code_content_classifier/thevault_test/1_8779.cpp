bool StudentDB::check_lastname(string lastname) {
//cout<<"ln pre for"<<endl;
	for (int i=0; i < lastname.size(); i++) {
		// Are there any non-alphabetic characters?
		if (!isalpha(lastname[i])) {
			// Yes, ths last name is invalid
//cout<<"ln if"<<endl;
			return false;
		}
//cout<<"ln for"<<endl;
	}
	return true;
}