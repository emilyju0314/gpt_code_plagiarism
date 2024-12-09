void Undergraduate::set_minor (string minor_title) {
	if(check_minor(minor_title)) {
		minor = minor_title;
	}else{
		minor = minor_title.substr(0,MAXIMUM_CHARACTERS_OF_MINOR);
	}
}