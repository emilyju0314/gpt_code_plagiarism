void Undergraduate::set_major (string major_title) {
	if(check_major(major_title)) {
		major = major_title;
	}else{
		major = major_title.substr(0,MAXIMUM_CHARACTERS_OF_MAJOR);
	}
}