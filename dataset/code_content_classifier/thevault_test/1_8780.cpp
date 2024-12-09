bool StudentDB::check_firstname(string firstname) {
//cout<<"fn pre for"<<endl;
	for (int i=0; i < firstname.size(); i++) {
		// Are there any non-alphabetic characters?
//cout<<"fn for"<<endl;
		if (!isalpha(firstname[i])) {
			// Yes, the last name is invalid
//cout<<"fn if"<<endl;
			return false;
		}
	}
	return true;
}