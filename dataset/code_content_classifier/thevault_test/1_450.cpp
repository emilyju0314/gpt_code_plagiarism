void DS1337::setDate(String date) {
	date.trim();
	if (date.length()==8)
	setDate(date.substring(0, 2).toInt(), date.substring(3, 5).toInt(), date.substring(6, 8).toInt());
}