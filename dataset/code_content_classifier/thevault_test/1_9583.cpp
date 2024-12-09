string MuseRecord::getGraphicNoteTypeField(void) {
// allowNotesOnly("getGraphicNoteTypefield");
	if (getLength() < 17) {
		return " ";
	} else {
		return extract(17, 17);
	}
}