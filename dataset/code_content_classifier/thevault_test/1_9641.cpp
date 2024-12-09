bool HumTransposer::setTransposition(int keyFifths, const string &semitones) {
	if (!isValidSemitones(semitones)) {
		return false;
	}
	int semis = stoi(semitones);
	return setTransposition(keyFifths, semis);
}