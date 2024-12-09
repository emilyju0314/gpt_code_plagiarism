void MuseRecordBasic::setTypeGraceChordNote(void) {
	setType(E_muserec_note_grace_chord);
	(*this)[0] = 'g';
	(*this)[1] = ' ';
}