bool Undergraduate::check_minor(string minor_title) {
	if (minor_title.size() > MAXIMUM_CHARACTERS_OF_MINOR) {
		// Minor title is too long
		return false;
	}else{
		return true;
	}
}