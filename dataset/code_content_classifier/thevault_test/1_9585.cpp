string MuseRecord::getProlongationField(void) {
//   allowNotesOnly("getProlongationField");   ---> rests also
	if (getLength() < 18) {
		return " ";
	} else {
		return extract(18, 18);
	}
}