void MuseRecordBasic::appendRational(HumNum& value) {
	stringstream tout;
	value.printTwoPart(tout);
	tout << ends;
	insertString(getLength()+1, tout.str());
}