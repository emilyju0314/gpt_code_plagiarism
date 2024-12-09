HumNum Convert::mensToDuration(HTp menstok) {
	int rlev = menstok->getValueInt("auto", "mensuration", "levels");
	if (rlev < 2222) {
		cerr << "Warning: cannot find mensuration levels for token " << menstok << endl;
		rlev = 2222;
	}
	return Convert::mensToDuration(*menstok, rlev);
}