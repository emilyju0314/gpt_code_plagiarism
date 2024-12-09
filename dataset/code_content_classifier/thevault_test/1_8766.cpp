bool Undergraduate::check_major(string major_title) {
	if (major_title.size() > MAXIMUM_CHARACTERS_OF_MAJOR) {
		// Major title is too long
		return false;
	}else{
		return true;
	}
}