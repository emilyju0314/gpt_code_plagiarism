bool StudentDB::check_studentage(int age) {
	if((age<1) || (age>120)) {
		return false;
	}else{
		return true;
	}
}