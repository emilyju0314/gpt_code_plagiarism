string NoteCell::getSgnKernPitch(void) {
	if (isRest()) {
		return "r";
	}
	string pitch;
	pitch = Convert::base40ToKern((int)getAbsBase40Pitch());
	if (isSustained()) {
		pitch.insert(0, "(");
		pitch += ")";
	}
	return pitch;
}