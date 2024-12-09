Student_list_pointer StudentDB::find_student(string ssn) {
	if(!check_socialsecuritynumber(ssn)) {
		cout << "Social security number entered is invalid" << endl;
		return database.end();
	}else{
		Student_list_pointer p = database.begin();
int j=0;
		while(p != database.end()) {
			if(((*p)->get_ssn()) == ssn) {
cout<<"p is: "<<j<<endl;
				return p;
			}else{
int j=0;
				p++;
			}
		}
		return database.end();
	}
}