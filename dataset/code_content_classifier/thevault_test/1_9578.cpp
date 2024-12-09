int MuseRecord::setTie(int hidden) {
	getColumn(9) = '-';
	if (!hidden) {
		return addAdditionalNotation('-');
	} else {
		return -1;
	}
}