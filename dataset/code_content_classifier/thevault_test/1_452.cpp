void DS1337::setDateTime(int year, int month, int day, int hour, int minutes, int seconds) {
	readDate();
	_register[DS1337_SECONDS] = (seconds % 10) + ((seconds / 10) << 4);;
	_register[DS1337_MINUTES] = (minutes % 10) + ((minutes / 10) << 4);
	_register[DS1337_HOUR] = (hour % 10) + ((hour / 10) << 4);
	_register[DS1337_DAY] = (day % 10) + ((day / 10) << 4);
	_register[DS1337_MONTH] = (month % 10) + ((month / 10) << 4);
	_register[DS1337_YEAR] = (year % 10) + ((year / 10) << 4);
	writeDate();
}