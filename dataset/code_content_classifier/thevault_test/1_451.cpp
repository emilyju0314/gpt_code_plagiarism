void DS1337::setDateTime(String date) {
	date.trim();
	if (date.length()==14)
	setDateTime(date.substring(0, 2).toInt(), date.substring(3, 5).toInt(), date.substring(6, 8).toInt(), date.substring(9, 11).toInt(), date.substring(12, 14).toInt(), 0);
}