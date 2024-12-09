bool check_last_name(string lastname) {
	for (int i=0; i < lastname.size(); i++) {
		// Are there any non-alphabetic characters?
		if (!isalpha(lastname[i])) {
			// Yes, ths last name is invalid
			return false;
		}
	}
	return true;
}