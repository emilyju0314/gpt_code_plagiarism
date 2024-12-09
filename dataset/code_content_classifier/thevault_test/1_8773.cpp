bool check_first_name(string firstname) {
	for (int i=0; i < firstname.size(); i++) {
		// Are there any non-alphabetic characters?
		if (!isalpha(firstname[i])) {
			// Yes, the last name is invalid
			return false;
		}
	}
	return true;
}